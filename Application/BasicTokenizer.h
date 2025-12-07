#pragma once

#include "ITokenizer.h"

class BasicTokenizer : public ITokenizer {
public:
	std::vector<std::string> tokenize(std::string line) override;
	virtual ~BasicTokenizer() {}
};

