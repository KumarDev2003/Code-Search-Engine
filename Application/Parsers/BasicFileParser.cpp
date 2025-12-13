#include <iostream>
#include <filesystem>
#include <fstream>
#include <memory>

#include "BasicFileParser.h"
#include "BasicTokenizer.h"
#include "IndexManager.h"
#include "DirectoryScanner.h"

void BasicFileParser::ParseFile(std::string filePath) {

    std::filesystem::path rootDir(filePath);

    std::unique_ptr<ITokenizer> tokener = std::make_unique<BasicTokenizer>();
    IndexManager* idxMgr = IndexManager::getInstance();

    std::unique_ptr<DirectoryScanner> dirScannner = std::make_unique<DirectoryScanner>();
    std::vector<std::filesystem::directory_entry> files = dirScannner->getFiles(rootDir);
    std::unordered_map<std::string, int> fileMap;
    std::unordered_map<std::string, std::vector<Location>> wordMap;

    int fileMapCnt = 0;

    for (std::filesystem::directory_entry file : files) {
        if (!file.is_regular_file()) continue;
        if (file.path().extension().string() != ".cpp" && file.path().extension().string() != ".h") continue;

        fileMap[file.path().string()] = fileMapCnt;

        std::ifstream reader;
        reader.open(file.path());

        std::string line;
        std::getline(reader, line);
        int lineNo = 1;
        while (!reader.eof()) {
            std::vector<std::string> words = tokener->tokenize(line);
            Location location(lineNo, fileMapCnt);
            for (std::string word : words) {
                idxMgr->addEntry(word, location); // Will remove it from here
                wordMap[word].push_back(location);
            }
            std::getline(reader, line);
            lineNo++;
        }
        fileMapCnt++;
        reader.close();
    }
    idxMgr->indexSave(rootDir, fileMap, wordMap);
}
