#include <iostream>

#include "FileTreeConsoleInterface.h"

#include "FileIterator.h"

int main(int argc, const char * argv[]) {
	const char* folderPath = (argv[1] != NULL) ? argv[1] : ".";

	/*FileTreeConsoleInterface interface(folderPath);
	interface.startGettingInput();*/

	FileIterator iter(folderPath);

	File* file;
	while(!iter.isFinished()) {
		iter.nextFile();
		if(file = dynamic_cast<File*>(iter.getData())) {
			std::cout<< file->getName()<< std::endl;
		}
	}

	return 0;
}
