#include "BaseFile.h"
#include "File.h"

void File::copy(const File& other) {
	BaseFile::copy(other);
	setSize(other.size);
}

File::File(const char* name, int size, FileStatus status): 
			BaseFile(name), size(size), status(status) {}

void File::setSize(int newSize) {
	size = newSize;
}

void File::setStatus(FileStatus newStatus) {
	status = newStatus;
}

int File::getSize() const {
	return size;
}

FileStatus File::getStatus() const {
	return status;
}
