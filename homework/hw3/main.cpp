#include <iostream>

#include "FileTreeConsoleInterface.h"

int main(int argc, const char * argv[]) {
	const char* folderPath = (argc > 1) ? argv[1] : ".";
	const char* pattern = (argc > 2) ? argv[2] : NULL;

	FileTreeConsoleInterface interface(folderPath, pattern);
	interface.startGettingInput();

	return 0;
}
