#include <iostream>
#include <format>

#include "IndexManager.h"
#include "DataBaseFactory.h"

IndexManager* IndexManager::idxMgr = nullptr;

void IndexManager::addEntry(std::string word, Location location) {
    wordIndex[word].push_back(location);
}

ResultData IndexManager::getResults(std::string word) {
    IndexManager* idxMgr = IndexManager::getInstance();
    ResultData resultData;
    resultData.fileIndex = idxMgr->fileIndex;
    resultData.wordLocations = idxMgr->wordIndex[word];
    return resultData;
}

void IndexManager::indexSave(std::filesystem::path dirPath, std::unordered_map<int, std::string> fileMap,
    std::unordered_map<std::string, std::vector<Location>> wordMap) {
    IDataBase* db = DataBaseFactory::getDB("FileDataBase");
    db->save(dirPath, fileMap, wordMap);
    db->load(dirPath, fileIndex, wordIndex);
}

void IndexManager::indexLoad(std::filesystem::path dirPath, std::unordered_map<int, std::string>& fileMap,
    std::unordered_map<std::string, std::vector<Location>>& wordMap) {
    IDataBase* db = DataBaseFactory::getDB("FileDataBase");
    db->load(dirPath, fileIndex, wordIndex);
}
