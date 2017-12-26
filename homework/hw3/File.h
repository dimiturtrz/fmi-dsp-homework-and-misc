#include "BaseFile.h"

#ifndef FILE
#define FILE

enum FileStatus { regular, created, deleted };

class File: public BaseFile {
private:
	int size;
	FileStatus status;

	void copy(const File& other);
public:
	File(const char* name, int size, FileStatus status = regular);
	
	void setSize(int newSize);
	void setStatus(FileStatus newStatus);

	int getSize();
	FileStatus getStatus();
};

#endif
