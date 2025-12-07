#include <iostream>
#include <filesystem>
#include <fstream>

#include "BasicFileParser.h"
#include "BasicTokenizer.h"
#include "IndexManager.h"

void BasicFileParser::ParseFile(std::string filePath) {
    std::vector<std::string> files;

    std::filesystem::path rootDir(filePath);

    ITokenizer* tokener = new BasicTokenizer();
    IndexManager* idxMgr = IndexManager::getInstance();

    for (auto& entry : std::filesystem::recursive_directory_iterator(rootDir)) {
        
        if (!entry.is_regular_file()) continue;
        if(entry.path().extension().string() != ".cpp" && entry.path().extension().string() != ".h") continue;

        std::ifstream reader;
        reader.open(entry.path());
        
        std::string line;
        std::getline(reader, line);
        int lineNo = 1;
        while (!reader.eof()) {
            std::vector<std::string> words = tokener->tokenize(line);
            Location location(lineNo, entry.path().string(), line);
            for (std::string word : words) {
            idxMgr->addEntry(word, location);
            }
            std::getline(reader, line);
            lineNo++;
        }
        reader.close();
    }
    delete tokener;
}
