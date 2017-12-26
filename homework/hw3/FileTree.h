#include <iostream>

#include "File.h"
#include "Folder.h"

#ifndef FILE_TREE
#define FILE_TREE

class FileTree {
private:
	Folder root;
	const char* filePattern;

	void normalize();
	void obsolete();

	void buildTree(const char* rootFolderPath);
public:
	FileTree(const char* rootFolderPath, const char* pattern);

	void refresh();
	void print(const char* pattern = NULL);
};

#endif
