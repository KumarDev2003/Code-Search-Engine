#include <filesystem>

#include "DirectoryScanner.h"

std::vector<std::filesystem::directory_entry> DirectoryScanner::getFiles(std::filesystem::path path){
	std::vector<std::filesystem::directory_entry> files;
	for (auto& entry : std::filesystem::recursive_directory_iterator(path)) {
		files.push_back(entry);
	}
	return files;
}
