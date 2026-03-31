CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall

TARGET = code
SOURCES = main.cpp
HEADERS = evil.hpp

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: clean
