#include "BaseFile.h"
#include "MyStrings.h"

void BaseFile::copy(const BaseFile& other) {
	setName(other.name);
}

void BaseFile::clear() {
	delete [] name;
	name = NULL;
}

BaseFile::BaseFile(const char* name): name(NULL) {
	setName(name);
}
BaseFile::BaseFile(const BaseFile& other): name(NULL) {
	copy(other);
}
BaseFile& BaseFile::operator=(const BaseFile& other) {
	if(this != &other) {
 		copy(other);
	}
	return *this;
}
BaseFile::~BaseFile() {
	clear();
}

void BaseFile::setName(const char* newName) {
	dynamicStrCpy(this->name, newName);
}

const char* BaseFile::getName() const {
	return name;
}

