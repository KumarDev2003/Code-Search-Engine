#include <string>
#include <unordered_map>

#pragma once

class ResultData {
public:
    std::unordered_map<int, std::string> fileIndex;
    std::vector<Location> wordLocations;
};