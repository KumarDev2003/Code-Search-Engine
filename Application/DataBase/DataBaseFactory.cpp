#include "DataBaseFactory.h"
#include "FileDataBase.h"

IDataBase * DataBaseFactory::getDB(std::string db) {
	if (db == "FileDataBase") return FileDataBase::getInstance();
	else return nullptr;
}
