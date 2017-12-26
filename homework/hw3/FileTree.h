#include <iostream>

#include "File.h"
#include "Folder.h"

#ifndef FILE_TREE
#define FILE_TREE

class FileTree {
private:
	Folder root;

public:
	FileTree(const char* rootFolderPath);

	void refresh();
	void print(const char* pattern);
};

#endif
