#include "SearchStrategy.h"
#include "BasicSearchEngine.h"

std::unique_ptr<ISearchEngine> SearchStrategy::strategy(std::string type) {
	if (type == "basic") return std::make_unique<BasicSearchEngine>();
	else return nullptr;
}