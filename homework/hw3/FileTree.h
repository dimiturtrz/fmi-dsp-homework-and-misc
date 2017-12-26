#include <iostream>

#include "File.h"
#include "Folder.h"

#ifndef FILE_TREE
#define FILE_TREE

class FileTree {
private:
	Folder* root;

	void clear();
	void copy(const FileTree& other);
public:
	FileTree(const char* rootFolderPath);
	FileTree(const FileTree& other);
	FileTree& operator=(const FileTree& other);
	~FileTree();

	void refresh();
	void print(const char* pattern);
};

#endif
