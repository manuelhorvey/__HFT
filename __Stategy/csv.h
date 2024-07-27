// csv.h
#ifndef CSV_H
#define CSV_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class CSVReader {
public:
    CSVReader(const std::string& filename);
    bool readNext(std::vector<std::string>& row);

private:
    std::ifstream file;
};

#endif // CSV_H
