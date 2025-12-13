#include <iostream>

#include "SearchCommand.h"
#include "BasicSearchEngine.h"
#include "SearchStrategy.h"

void SearchCommand::execute(std::string word) {
	std::unique_ptr<ISearchEngine> basicSearchEngine = SearchStrategy::strategy("basic");
	std::vector<Location> result = basicSearchEngine->search(word);
	std::cout << "\nTotal occurnce of \"" << word << "\" is " << result.size() << std::endl;
	for (Location word : result) {
		std::cout << "{\n";
		std::cout << word.fileIndex << "\n";
		std::cout << "Line no. " << word.lineNumber << std::endl;
		std::cout << "}\n";
	}
}