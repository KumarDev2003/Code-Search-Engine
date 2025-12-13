#pragma once

#include <vector>
#include <string>

#include "Location.h"


class ISearchEngine {
public:
	virtual std::vector<Location> search(std::string word) = 0;
	virtual ~ISearchEngine() {}
};