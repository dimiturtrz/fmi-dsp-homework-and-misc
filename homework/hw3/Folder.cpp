#include "Folder.h"
#include "MyStrings.h"

Folder::Folder(const char* name, Folder* parent): BaseFile(name), parent(parent) {}

void Folder::addFile(const File& file) {
	std::vector<File>::iterator iter = files.begin();
	for(; (iter != files.end() && (strcmp(file.getName(), (*iter).getName()) > 0)); ++iter);
	files.insert(iter, file);
}
void Folder::addFolder(const Folder& folder) {
	std::vector<Folder>::iterator iter = subfolders.begin();
	for(; (iter != subfolders.end() && (strcmp(folder.getName(), (*iter).getName()) > 0)); ++iter);
	subfolders.insert(iter, folder);
}

const std::vector<File>& Folder::getFiles() const {
	return files;
}
const std::vector<Folder>& Folder::getSubfolders() const {
	return subfolders;
}

Folder& Folder::getTopSubfolder() {
	return subfolders.back();
}
Folder& Folder::getParent() {
	return *parent;
}

void Folder::setParent(Folder* newParent) {
	parent = newParent;
}

void Folder::print(char*& currPath) const {
	std::vector<File>::const_iterator fileIter = files.begin();
	std::vector<Folder>::const_iterator folderIter = subfolders.begin();

	while((fileIter != files.end()) || (folderIter != subfolders.end())) {
		if(folderIter == subfolders.end() || (fileIter != files.end() &&
			(strcmp(fileIter->getName(), folderIter->getName()) <= 0))) {
			appendComponentToPath(currPath, fileIter->getName());
			++fileIter;
			std::cout<< currPath<< std::endl;
		} else {
			appendComponentToPath(currPath, folderIter->getName());
			folderIter->print(currPath);
			++folderIter;
		}
		removeLastComponentFromPath(currPath);
	}
}
