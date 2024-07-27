#ifndef ORDER_H
#define ORDER_H

#include "SimplePrice.h"

class Order {
public:
    enum class Type { Buy, Sell };

    Order() : _price(0.0), _type(Type::Buy) {} // Default constructor
    Order(const SimplePrice& price, Type type) : _price(price), _type(type) {}

    void setPrice(const SimplePrice& price);
    void setType(Type type);

    SimplePrice getPrice() const { return _price; }
    Type getType() const { return _type; }

private:
    SimplePrice _price;
    Type _type;
};

#endif // ORDER_H
