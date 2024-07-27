#include "SimplePrice.h"

// Define the constructor
SimplePrice::SimplePrice(double price) : _price(price) {}

// Define the comparison operators
bool SimplePrice::operator>(const SimplePrice& other) const {
    return _price > other._price;
}

bool SimplePrice::operator<(const SimplePrice& other) const {
    return _price < other._price;
}

bool SimplePrice::operator==(const SimplePrice& other) const {
    return _price == other._price;
}

bool SimplePrice::operator!=(const SimplePrice& other) const {
    return _price != other._price;
}

// Define the getPrice method
double SimplePrice::getPrice() const {
    return _price;
}
