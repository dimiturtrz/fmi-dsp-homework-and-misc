#include "File.h"

#ifndef FOLDER
#define FOLDER

class Folder: File {
	File* files;
	Folder* subfolders;
};

#endif
