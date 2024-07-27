#include <iostream>
#include "OrderStrategy033.h"
#include "QuoteEvent.h"
#include "OrderVectors.h"

bool OrderStrategy033::isValidQuote(const QuoteEvent& qe) const {
    const double MIN_PRICE = 0.01;
    const double MAX_PRICE = 10000.0;

    double price = qe.getPrice();
    if (price <= MIN_PRICE || price > MAX_PRICE) {
        return false;
    }

    SimplePrice bid = qe.getBid();
    SimplePrice ask = qe.getAsk();
    if (bid > ask) {
        return false;
    }

    Venue venue = qe.getVenue();
    if (venue != _pricingVenue) {
        return false;
    }

    return true;
}

void OrderStrategy033::handle(const QuoteEvent& qe, OrderVectors& orders) {
    //check the new quote and update the cache quote
    if (!_initialized) return;
    if (qe.getVenue() != _pricingVenue) return;

    SimplePrice newBid = qe.getBid();
    SimplePrice newAsk = qe.getAsk();

    std::cout << "Handling quote. New Bid: " << newBid.getPrice() << ", Previous Bid: " << _bid.getPrice() << std::endl;
    std::cout << "Handling quote. New Ask: " << newAsk.getPrice() << ", Previous Ask: " << _ask.getPrice() << std::endl;

    if (newBid < _bid) {
        Order order(newBid, Order::Type::Buy);
        orders.orders.push_back(order);
        std::cout << "Added Buy Order with Bid: " << newBid.getPrice() << std::endl;
    }

    if (newAsk > _ask) {
        Order order(newAsk, Order::Type::Sell);
        orders.orders.push_back(order);
        std::cout << "Added Sell Order with Ask: " << newAsk.getPrice() << std::endl;
    }

    _bid = newBid;
    _ask = newAsk;
}
