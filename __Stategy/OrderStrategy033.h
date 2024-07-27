#ifndef ORDER_STRATEGY_033_H
#define ORDER_STRATEGY_033_H

#include "QuoteEvent.h"
#include "OrderVectors.h"
#include "Venue.h"

class OrderStrategy033 {
public:
    OrderStrategy033(const Venue& pricingVenue) 
        : _pricingVenue(pricingVenue), _initialized(true), _bid(0.0), _ask(0.0) {}

    bool isValidQuote(const QuoteEvent& qe) const;
    void handle(const QuoteEvent& qe, OrderVectors& orders);

private:
    Venue _pricingVenue;
    bool _initialized;
    SimplePrice _bid;
    SimplePrice _ask;
};

#endif // ORDER_STRATEGY_033_H
