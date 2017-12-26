#include "BaseFile.h"
#include "File.h"

void File::copy(const File& other) {
	BaseFile::copy(other);
	setSize(other.size);
}

File::File(const char* name, int size): BaseFile(name), size(size) {}

void File::setSize(int newSize) {
	size = newSize;
}

int File::getSize() {
	return size;
}
