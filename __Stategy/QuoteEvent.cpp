#include "QuoteEvent.h"

Venue QuoteEvent::getVenue() const {
    return _venue;
}

SimplePrice QuoteEvent::getBid() const {
    return _bid;
}

SimplePrice QuoteEvent::getAsk() const {
    return _ask;
}

double QuoteEvent::getPrice() const {
    return _price;
}


void QuoteEvent::setPrice(double price) {
    _price = price;
}

void QuoteEvent::setBid(const SimplePrice& bid) {
    _bid = bid;
}

void QuoteEvent::setAsk(const SimplePrice& ask) {
    _ask = ask;
}

void QuoteEvent::setVenue(const Venue& venue) {
    _venue = venue;
}
