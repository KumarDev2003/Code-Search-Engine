#pragma once

#include "ICommand.h"

class SearchCommand : public ICommand {
public:
	void execute(std::string word);
};