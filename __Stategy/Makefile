# Define compiler and flags
CXX = g++
CXXFLAGS = -Wall -g

# Define targets and sources
TARGET = main
OBJS = SimplePrice.o Venue.o QuoteEvent.o Order.o OrderStrategy033.o main.o csv.o

# Default target
all: $(TARGET)

# Link the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
SimplePrice.o: SimplePrice.cpp SimplePrice.h
	$(CXX) $(CXXFLAGS) -c SimplePrice.cpp -o SimplePrice.o

Venue.o: Venue.cpp Venue.h
	$(CXX) $(CXXFLAGS) -c Venue.cpp -o Venue.o

QuoteEvent.o: QuoteEvent.cpp QuoteEvent.h Venue.h SimplePrice.h
	$(CXX) $(CXXFLAGS) -c QuoteEvent.cpp -o QuoteEvent.o

Order.o: Order.cpp Order.h SimplePrice.h
	$(CXX) $(CXXFLAGS) -c Order.cpp -o Order.o

OrderStrategy033.o: OrderStrategy033.cpp OrderStrategy033.h QuoteEvent.h OrderVectors.h SimplePrice.h Venue.h
	$(CXX) $(CXXFLAGS) -c OrderStrategy033.cpp -o OrderStrategy033.o

main.o: main.cpp OrderStrategy033.h QuoteEvent.h OrderVectors.h SimplePrice.h Venue.h csv.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

csv.o: csv.cpp csv.h
	$(CXX) $(CXXFLAGS) -c csv.cpp -o csv.o

# Clean up build artifacts
clean:
	rm -f $(TARGET) $(OBJS)
