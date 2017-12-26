#include <iostream>
#include <vector>

#include "File.h"

#ifndef FOLDER
#define FOLDER

class Folder: public BaseFile {
private:
	Folder* parent;
	std::vector<File> files;
	std::vector<Folder> subfolders;

public:
	Folder(const char* name, Folder* parent = NULL);

	void addFile(const File& file);
	void addFolder(const Folder& folder);

	const std::vector<File>& getFiles() const;
	const std::vector<Folder>& getSubfolders() const;
	
	void setParent(Folder* newParent);	
};

#endif
