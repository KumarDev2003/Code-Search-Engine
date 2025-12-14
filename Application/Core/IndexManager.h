#pragma once

#include <vector>
#include <unordered_map>
#include <filesystem>

#include "Location.h"
#include "ResultData.h"

class IndexManager {
    IndexManager() {}
public:
    static IndexManager* idxMgr;
    std::unordered_map<int, std::string> fileIndex;
    std::unordered_map<std::string, std::vector<Location>> wordIndex;
    void addEntry(std::string word, Location location);
    ResultData getResults(std::string word);
    static IndexManager* getInstance() {
        if (!idxMgr) return idxMgr = new IndexManager();
        else return idxMgr;
    }
    void indexSave(std::filesystem::path dirPath, std::unordered_map<int, std::string> fileMap,
        std::unordered_map<std::string, std::vector<Location>> wordMap);
    void indexLoad(std::filesystem::path dirPath, std::unordered_map<int, std::string>& fileMap,
        std::unordered_map<std::string, std::vector<Location>>& wordMap);
    virtual ~IndexManager(){}
};
