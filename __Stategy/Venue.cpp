#include "Venue.h"

// Default constructor
Venue::Venue() : id(0) {}

// Parameterized constructor
Venue::Venue(int venueId) : id(venueId) {}

// Comparison operator
bool Venue::operator!=(const Venue& other) const {
    return id != other.id;
}

// Comparison operator
bool Venue::operator==(const Venue& other) const {
    return id == other.id;
}

// Getter for venue ID
int Venue::getId() const {
    return id;
}

// Setter for venue ID
void Venue::setId(int venueId) {
    id = venueId;
}
