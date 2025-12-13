#pragma once

#include <memory>

#include "IDataBase.h"

class DataBaseFactory {
public:
	static IDataBase * getDB(std::string db);
};