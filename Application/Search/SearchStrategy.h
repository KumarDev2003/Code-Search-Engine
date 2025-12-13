#pragma once

#include <string>
#include <memory>

#include "ISearchEngine.h"

class SearchStrategy {
public:
	static std::unique_ptr<ISearchEngine> strategy(std::string type);
};