#pragma once

#include <string>

class Location {
    // private:
public:
    int lineNumber;
    int fileIndex;
public:
    Location(int lineNumber, int fileIndex)
        : lineNumber(lineNumber), fileIndex(fileIndex) {
    }
    virtual ~Location() {}
};
