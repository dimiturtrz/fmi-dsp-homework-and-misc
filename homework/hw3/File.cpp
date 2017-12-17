#include "File.h"
#include "MyStrings.h"

void File::copy(const File& other) {
	setName(other.name);
	setSize(other.size);
}

void File::clear() {
	delete [] name;
}

File::File(const char* name, int size): size(size), name(NULL) {
	setName(name);
}
File::File(const File& other) {
	copy(other);
}
File& File::operator=(const File& other) {
	if(this != &other) {
		copy(other);
	}
	return *this;
}
File::~File() {
	clear();
}

void File::setName(const char* newName) {
	dynamicStrCpy(this->name, name);
}
void File::setSize(int newSize) {
	size = newSize;
}

const char* File::getName() {}
int File::getSize() {}
