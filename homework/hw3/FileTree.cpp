#include "FileTree.h"
#include "FileIterator.h"


void FileTree::clear() {}
void FileTree::copy(const FileTree& other) {}

FileTree::FileTree(const char* rootFolderPath) {
	FileIterator iter(rootFolderPath);
	BaseFile* currFile;
	while(!iter.isFinished()) {
		
	}
}

FileTree::FileTree(const FileTree& other) {}
FileTree& FileTree::operator=(const FileTree& other) {}
FileTree::~FileTree() {}


void FileTree::refresh() {}
void FileTree::print(const char* pattern) {}
