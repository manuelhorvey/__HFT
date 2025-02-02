#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "OrderStrategy033.h"
#include "QuoteEvent.h"
#include "OrderVectors.h"
#include "SimplePrice.h"
#include "Venue.h"
#include "csv.h"

// Function to trim leading and trailing whitespace
std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    if (start == std::string::npos || end == std::string::npos) {
        return "";
    }
    return str.substr(start, end - start + 1);
}

// Function to parse CSV fields, handling quotes and commas
std::vector<std::string> parseCSVLine(const std::string& line) {
    std::vector<std::string> fields;
    std::stringstream ss(line);
    std::string field;
    char delimiter = ',';
    char quote = '"';

    bool insideQuote = false;
    while (ss.get(delimiter)) {
        if (delimiter == quote) {
            insideQuote = !insideQuote;
        } else if (delimiter == ',' && !insideQuote) {
            fields.push_back(trim(field));
            field.clear();
        } else {
            field += delimiter;
        }
    }
    fields.push_back(trim(field)); // Add the last field

    return fields;
}

// Function to clean and parse a CSV field
std::string cleanField(const std::string& field) {
    std::string cleaned = field;

    // Remove surrounding quotes
    if (!cleaned.empty() && cleaned.front() == '"' && cleaned.back() == '"') {
        cleaned = cleaned.substr(1, cleaned.size() - 2);
    }

    // Trim spaces
    cleaned = trim(cleaned);

    return cleaned;
}

// Function to correct and parse a price with potential commas
double correctPrice(const std::string& priceStr) {
    std::string cleanedPrice = priceStr;

    // Remove commas
    cleanedPrice.erase(std::remove(cleanedPrice.begin(), cleanedPrice.end(), ','), cleanedPrice.end());

    if (cleanedPrice.empty()) {
        return 0.0; // Handle empty fields gracefully
    }

    try {
        return std::stod(cleanedPrice);
    } catch (const std::exception& e) {
        std::cerr << "Error converting cleaned price string to double: " << cleanedPrice << " - " << e.what() << std::endl;
        return 0.0; // Return a default value or handle error appropriately
    }
}

// Function to convert a cleaned string to double
double toDouble(const std::string& str) {
    if (str.empty()) {
        return 0.0; 
    }
    try {
        return std::stod(str);
    } catch (const std::exception& e) {
        std::cerr << "Error converting string to double: " << str << " - " << e.what() << std::endl;
        return 0.0;
    }
}

// Function to parse and process the CSV file
void processCSV(const std::string& filePath) {
    // Create an instance of OrderStrategy033 with a Venue
    Venue pricingVenue(1);
    OrderStrategy033 strategy(pricingVenue);

    // Create an instance of OrderVectors
    OrderVectors orders;

    // Read all lines into a vector
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;
    bool isFirstRow = true; 

    while (std::getline(file, line)) {
        if (isFirstRow) {
            isFirstRow = false; 
            continue;
        }
        lines.push_back(line);
    }

    // Process the lines from bottom to top
    for (auto it = lines.rbegin(); it != lines.rend(); ++it) {
        const std::string& line = *it;

        std::vector<std::string> row = parseCSVLine(line);
        std::cout << "Raw CSV row: ";
        for (const auto &field : row) {
            std::cout << "\"" << field << "\" ";
        }
        std::cout << std::endl;

        if (row.size() >= 7) { 
            try {
                // Clean and convert each field
                std::string date = cleanField(row[0]);
                double open = correctPrice(cleanField(row[1]));
                double high = correctPrice(cleanField(row[2]));
                double low = correctPrice(cleanField(row[3]));
                double close = correctPrice(cleanField(row[4]));
                double changePips = toDouble(cleanField(row[5]));
                double changePercent = toDouble(cleanField(row[6]));

                // Debug output
                std::cout << "Processed row - Date: " << date
                          << ", Open: " << open
                          << ", High: " << high
                          << ", Low: " << low
                          << ", Close: " << close
                          << ", Change Pips: " << changePips
                          << ", Change %: " << changePercent << std::endl;

                // Create a QuoteEvent from the CSV data
                QuoteEvent quoteEvent;
                quoteEvent.setPrice(open);
                quoteEvent.setBid(SimplePrice(open));
                quoteEvent.setAsk(SimplePrice(high));
                quoteEvent.setVenue(pricingVenue);

                // Validate and handle the quote
                if (strategy.isValidQuote(quoteEvent)) {
                    std::cout << "Quote is valid." << std::endl;
                } else {
                    std::cout << "Quote is invalid." << std::endl;
                }

                strategy.handle(quoteEvent, orders);
            } catch (const std::exception &e) {
                std::cerr << "Error parsing CSV row: " << e.what() << std::endl;
                continue;
            }
        } else {
            std::cerr << "Invalid row: not enough columns" << std::endl;
        }
    }

    // Output results
    std::cout << "Orders count: " << orders.orders.size() << std::endl;
    for (const auto &order : orders.orders) {
        std::cout << (order.getType() == Order::Type::Buy ? "Buy" : "Sell")
                  << " order at price: " << order.getPrice().getPrice() << std::endl;
    }
}

int main() {
    std::string filePath = "./Data/XAUUSD_historical_data.csv";
    processCSV(filePath);
    return 0;
}
