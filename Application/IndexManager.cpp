#include "IndexManager.h"

IndexManager* IndexManager::idxMgr = nullptr;

void IndexManager::addEntry(std::string word, Location location) {
    IndexManager* idxMgr = IndexManager::getInstance();
    idxMgr->wordIndex[word].push_back(location);
}

std::vector<Location> IndexManager::getResults(std::string word) {
    IndexManager* idxMgr = IndexManager::getInstance();
    return idxMgr->wordIndex[word];
}
