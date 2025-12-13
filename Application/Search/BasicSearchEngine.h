#pragma once

#include "ISearchEngine.h"

class BasicSearchEngine : public ISearchEngine {
public:
	std::vector<Location> search(std::string word) override;
	virtual ~BasicSearchEngine() {}
};