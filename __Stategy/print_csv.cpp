#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

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
    fields.push_back(trim(field));

    return fields;
}

void printCSV(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return;
    }

    while (std::getline(file, line)) {
        // Parse CSV line
        std::vector<std::string> fields = parseCSVLine(line);

        // Output fields with proper formatting
        if (fields.size() > 0) {
            std::cout << fields[0]; // Date

            for (size_t i = 1; i < fields.size(); ++i) {
                std::cout << " | " << fields[i];
            }
            std::cout << std::endl;
        }
    }

    file.close();
}

int main() {
    std::string filePath = "XAU_USD_Historical_Data.csv";
    printCSV(filePath);
    return 0;
}
