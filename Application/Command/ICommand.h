#pragma once

#include <string>

class ICommand {
public:
	virtual void execute(std::string parameter) = 0;
};
