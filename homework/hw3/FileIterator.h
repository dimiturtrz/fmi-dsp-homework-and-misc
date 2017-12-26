#include <dirent.h>
#include <iostream>
#include <stack>

#include "BaseFile.h"

#ifndef FILE_ITERATOR
#define FILE_ITERATOR

class FileIterator {
private:
	BaseFile* data;

	char* currDirPath;
	std::stack<DIR*> streamStack;

	const char* pattern;

	void copy(const FileIterator& other);
public:
	FileIterator(const char* path = ".", const char* pattern = NULL);
	FileIterator(const FileIterator& other);
	FileIterator& operator=(const FileIterator& other);
	~FileIterator();

	void nextFile();

	BaseFile* getData();
	void setData(BaseFile* newData);

	bool isFinished();
};

#endif
