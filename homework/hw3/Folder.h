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

	void setGlobalStatus(FileStatus status);
public:
	Folder(const char* name, Folder* parent = NULL);

	File* addFile(File& file);
	Folder* addFolder(const Folder& folder);

	const std::vector<File>& getFiles() const;
	const std::vector<Folder>& getSubfolders() const;

	Folder& getTopSubfolder();
	Folder& getParent();
	void setParent(Folder* newParent);

	void print(char*& currPath, const char* pattern) const;

	void normalize();
	void obsolete();
};

#endif
