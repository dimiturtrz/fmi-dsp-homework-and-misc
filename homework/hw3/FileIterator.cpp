#include <sys/stat.h>

#include "FileIterator.h"
#include "MyStrings.h"
#include "Patterns.h"
#include "File.h"
#include "Folder.h"

void FileIterator::copy(const FileIterator& other) {
	dynamicStrCpy(currDirPath, other.currDirPath);
	streamStack = other.streamStack;
	data = other.data;
}

FileIterator::FileIterator(const char* path, const char* pattern): currDirPath(NULL), data(NULL), pattern(pattern) {
	dynamicStrCpy(currDirPath, path);
	streamStack.push(opendir(path));
    nextFile();
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
		file && ((strcmp(file->d_name, ".") == 0 || strcmp(file->d_name, "..") == 0) 				 || (file->d_type == DT_REG && pattern != NULL && 
				!match(file->d_name, pattern)));
		file = readdir(dirStream));

	if(file) {
        appendComponentToPath(currDirPath, file->d_name);
		switch(file->d_type) {
		case DT_DIR:
			streamStack.push(opendir(currDirPath));
			setData(new Folder(file->d_name));
			return;
		case DT_REG:
			if (stat(currDirPath, &file_stats) == 0) {
				setData(new File(file->d_name, file_stats.st_size));
			} else {
                throw;
			}
            removeLastComponentFromPath(currDirPath);
            return;
		}
	}

	streamStack.pop();
	removeLastComponentFromPath(currDirPath);
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
