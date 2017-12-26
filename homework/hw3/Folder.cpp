#include "Folder.h"

Folder::Folder(const char* name, Folder* parent): BaseFile(name), parent(parent) {}

void Folder::addFile(const File& file) {
	files.push_back(file);
}
void Folder::addFolder(const Folder& folder) {
	subfolders.push_back(folder);
}

const std::vector<File>& Folder::getFiles() const {
	return files;
}
const std::vector<Folder>& Folder::getSubfolders() const {
	return subfolders;
}

void Folder::setParent(Folder* newParent) {
	parent = newParent;
}
