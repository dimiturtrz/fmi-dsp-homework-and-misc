#ifndef FILE_TREE_CONSOLE_INTERACE
#define FILE_TREE_CONSOLE_INTERACE

#include "FileTree.h"

class FileTreeConsoleInterface {
	bool gettingInput;
	FileTree fileTree;

public:

	FileTreeConsoleInterface(const char* folderPath, const char* pattern);

	void interpretInput(const char* command, const char* argument);
	void startGettingInput();
	void stopGettingInput();
};

#endif

