#include <iostream>
#include <format>

#include "IndexManager.h"
#include "DataBaseFactory.h"

IndexManager* IndexManager::idxMgr = nullptr;

void IndexManager::addEntry(std::string word, Location location) {
    wordIndex[word].push_back(location);
}

std::vector<Location> IndexManager::getResults(std::string word) {
    IndexManager* idxMgr = IndexManager::getInstance();
    return idxMgr->wordIndex[word];
}

void IndexManager::indexSave(std::filesystem::path dirPath, std::unordered_map<std::string, int> fileMap,
    std::unordered_map<std::string, std::vector<Location>> wordMap) {
    IDataBase* db = DataBaseFactory::getDB("FileDataBase");
    db->save(dirPath, fileMap, wordMap);
}

void IndexManager::indexLoad(std::filesystem::path dirPath, std::unordered_map<std::string, int>& fileMap,
    std::unordered_map<std::string, std::vector<Location>>& wordMap) {
    IDataBase* db = DataBaseFactory::getDB("FileDataBase");
    std::unordered_map<std::string, int> fileMa;
    std::unordered_map<std::string, std::vector<Location>> wordMa;
    db->load(dirPath, fileMa, wordMa);
}
