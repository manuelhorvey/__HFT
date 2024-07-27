#ifndef QUOTE_EVENT_H
#define QUOTE_EVENT_H

#include "Venue.h"
#include "SimplePrice.h"

class QuoteEvent {
public:
    Venue getVenue() const;
    SimplePrice getBid() const;
    SimplePrice getAsk() const;
    double getPrice() const; 

    void setPrice(double price);
    void setBid(const SimplePrice& bid);
    void setAsk(const SimplePrice& ask);
    void setVenue(const Venue& venue);

private:
    Venue _venue;
    SimplePrice _bid;
    SimplePrice _ask;
    double _price; 
};

#endif // QUOTE_EVENT_H
