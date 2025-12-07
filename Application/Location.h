#pragma once

#include <string>

class Location {
    // private:
public:
    int lineNumber;
    std::string filePath;
    std::string lineText;
public:
    Location(int lineNumber, std::string filePath, std::string lineText)
        : lineNumber(lineNumber), filePath(filePath), lineText(lineText) {
    }
    virtual ~Location() {}
};
