#pragma once

#include <vector>
#include <string>

#include "Location.h"
#include "ResultData.h"


class ISearchEngine {
public:
	virtual ResultData search(std::string word) = 0;
	virtual ~ISearchEngine() {}
};