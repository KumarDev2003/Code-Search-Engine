#pragma once

#include <string>
#include <vector>

class ITokenizer {
public:
	virtual std::vector<std::string> tokenize(std::string line) = 0;
	virtual ~ITokenizer(){}
};
