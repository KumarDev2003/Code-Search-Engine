#pragma once

#include "Location.h"
#include <vector>
#include <unordered_map>

class IndexManager {
    IndexManager() {}
public:
    static IndexManager* idxMgr;
    std::unordered_map<std::string, std::vector<Location>> wordIndex;
    void addEntry(std::string word, Location location);
    std::vector<Location> getResults(std::string word);
    static IndexManager* getInstance() {
        if (!idxMgr) return idxMgr = new IndexManager();
        else return idxMgr;
    }
    virtual ~IndexManager(){}
};
