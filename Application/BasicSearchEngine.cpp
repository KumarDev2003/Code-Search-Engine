#include "BasicSearchEngine.h"
#include "IndexManager.h"

std::vector<Location> BasicSearchEngine::search(std::string word) {
	IndexManager* idxMgr = IndexManager::getInstance();
	std::vector<Location> locations = idxMgr->getResults(word);
	return locations;
}
