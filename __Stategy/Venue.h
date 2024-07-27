#ifndef VENUE_H
#define VENUE_H

class Venue {
public:
    Venue(); // Default constructor
    Venue(int venueId); // Parameterized constructor

    bool operator!=(const Venue& other) const;
    bool operator==(const Venue& other) const;

    int getId() const;
    void setId(int venueId);

private:
    int id; // Identifier for the venue
};

#endif // VENUE_H
