#include "BasicSearchEngine.h"
#include "IndexManager.h"

ResultData BasicSearchEngine::search(std::string word) {
	IndexManager* idxMgr = IndexManager::getInstance();
	ResultData resultdata = idxMgr->getResults(word);
	return resultdata;
}
