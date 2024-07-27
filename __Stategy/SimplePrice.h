#ifndef SIMPLE_PRICE_H
#define SIMPLE_PRICE_H

class SimplePrice {
public:
    SimplePrice(double price = 0.0);

    bool operator>(const SimplePrice& other) const;
    bool operator<(const SimplePrice& other) const;
    bool operator==(const SimplePrice& other) const;
    bool operator!=(const SimplePrice& other) const;

    double getPrice() const;

private:
    double _price; // Example data member to hold price
};

#endif // SIMPLE_PRICE_H
