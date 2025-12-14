#pragma once

#include "ISearchEngine.h"

class BasicSearchEngine : public ISearchEngine {
public:
	ResultData search(std::string word) override;
	virtual ~BasicSearchEngine() {}
};