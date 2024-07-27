#include "Order.h"

void Order::setPrice(const SimplePrice& price) {
    _price = price;
}

void Order::setType(Type type) {
    _type = type;
}
