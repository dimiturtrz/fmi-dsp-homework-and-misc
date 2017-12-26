#include <iostream>

#include "FileTreeConsoleInterface.h"

int main(int argc, const char * argv[]) {
	const char* folderPath = (argv[1] != NULL) ? argv[1] : ".";

	FileTreeConsoleInterface interface(folderPath);
	interface.startGettingInput();

	return 0;
}
