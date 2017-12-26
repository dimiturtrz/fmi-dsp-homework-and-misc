#include "Folder.h"
#include "MyStrings.h"
#include "Patterns.h"

Folder::Folder(const char* name, Folder* parent): BaseFile(name), parent(parent) {}

File* Folder::addFile(File& file) {
	std::vector<File>::iterator iter = files.begin();
	for(; (iter != files.end() && (strcmp(file.getName(), (*iter).getName()) > 0)); ++iter);

	if((iter == files.end()) || (strcmp(iter->getName(), file.getName()) != 0)) {
		file.setStatus(created);
		return &(*(files.insert(iter, file)));
	}
	if(iter->getStatus() == deleted) {
		iter->setStatus(regular);
	}
	return &(*(iter));
}
Folder* Folder::addFolder(const Folder& folder) {
	std::vector<Folder>::iterator iter = subfolders.begin();
	for(; (iter != subfolders.end() && (strcmp(folder.getName(), (*iter).getName()) > 0)); ++iter);

	if((iter == subfolders.end()) || (strcmp(iter->getName(), folder.getName()) != 0)) {
		return &(*(subfolders.insert(iter, folder)));
	}
	return &(*(iter));
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

void Folder::print(char*& currPath, const char* pattern) const {
	std::vector<File>::const_iterator fileIter = files.begin();
	std::vector<Folder>::const_iterator folderIter = subfolders.begin();

	while((fileIter != files.end()) || (folderIter != subfolders.end())) {

        if(folderIter == subfolders.end() || (fileIter != files.end() &&
			(strcmp(fileIter->getName(), folderIter->getName()) <= 0))) {

			if(pattern == NULL || match(fileIter->getName(), pattern)) {
                appendComponentToPath(currPath, fileIter->getName());
                switch(fileIter->getStatus()) {
                    case created:
                        std::cout<< "+";
                        break;
                    case deleted:
                        std::cout<< "-";
                        break;
                    default:
                        std::cout<< " ";
                        break;
                }
                std::cout<< currPath<< std::endl;
                removeLastComponentFromPath(currPath);
			}
			++fileIter;
		} else {
			appendComponentToPath(currPath, folderIter->getName());
			folderIter->print(currPath, pattern);
			++folderIter;
            removeLastComponentFromPath(currPath);
		}
	}
}


void Folder::setGlobalStatus(FileStatus status) {
	for(std::vector<Folder>::iterator iter = subfolders.begin(); iter != subfolders.end(); ++iter) {
		iter->setGlobalStatus(status);
	}
	for(std::vector<File>::iterator iter = files.begin(); iter != files.end(); ++iter) {
		iter->setStatus(status);
	}
}

void Folder::normalize() {
	setGlobalStatus(regular);
}
void Folder::obsolete() {
	setGlobalStatus(deleted);
}
