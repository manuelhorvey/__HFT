// csv.cpp
#include "csv.h"

CSVReader::CSVReader(const std::string& filename) : file(filename) {}

bool CSVReader::readNext(std::vector<std::string>& row) {
    std::string line;
    if (std::getline(file, line)) {
        std::istringstream s(line);
        std::string field;
        row.clear();
        while (std::getline(s, field, ',')) {
            row.push_back(field);
        }
        return true;
    }
    return false;
}
