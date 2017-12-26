#include <sys/stat.h>

#include "FileIterator.h"
#include "MyStrings.h"
#include "File.h"
#include "Folder.h"

void FileIterator::copy(const FileIterator& other) {
	dynamicStrCpy(currDirPath, other.currDirPath);
	streamStack = other.streamStack;
	data = other.data;
}

void FileIterator::appendToCurrPath(const char* newComponent) {
	int len = strlen(currDirPath) + strlen(newComponent) + 2;
	char* newPath = new char[len];

	strcpy(newPath, currDirPath);
	strcat(newPath, "/");
	strcat(newPath, newComponent);

	delete [] currDirPath;
	currDirPath = newPath;
}
void FileIterator::removeLastComponentFromPath() {
	int len = strlen(currDirPath);
	for(; currDirPath[len] != '/' && len > 0; --len);
	currDirPath[len] = '\0';
}

FileIterator::FileIterator(const char* path): currDirPath(NULL), data(NULL) {
	dynamicStrCpy(currDirPath, path);
	streamStack.push(opendir(path));
}

FileIterator::FileIterator(const FileIterator& other) {
	copy(other);
}

FileIterator& FileIterator::operator=(const FileIterator& other) {
	if(this != &other) {
		copy(other);
	}
	return *this;
}

FileIterator::~FileIterator() {
	delete [] currDirPath;
	delete data;
}

void FileIterator::nextFile() {
	if(isFinished()) {
		data = NULL;
		return;
	}

	DIR* dirStream = streamStack.top();
	struct dirent* file;
	struct stat file_stats;
	for(file = readdir(dirStream);
		file && (strcmp(file->d_name, ".") == 0 || strcmp(file->d_name, "..") == 0);
		file = readdir(dirStream));

	if(file) {
		switch(file->d_type) {
		case DT_DIR:
			appendToCurrPath(file->d_name);
			streamStack.push(opendir(currDirPath));
			setData(new Folder(file->d_name));
			return;
		case DT_REG:
			if (!stat(file->d_name, &file_stats)) {
				setData(new File(file->d_name, file_stats.st_size));
				return;
			}
		}
	}

	streamStack.pop();
	removeLastComponentFromPath();
	data = NULL;
}

BaseFile* FileIterator::getData() {
	return data;
}

void FileIterator::setData(BaseFile* newData) {
	delete data;
	data = newData;
}

bool FileIterator::isFinished() {
	while(!streamStack.empty() && (streamStack.top() == NULL)) {
		streamStack.pop();
	}

	return streamStack.empty();
}
