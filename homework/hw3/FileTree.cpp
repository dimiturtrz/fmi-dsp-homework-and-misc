#include "FileTree.h"
#include "FileIterator.h"

#include "MyStrings.h"

void FileTree::normalize() {
	root.normalize();
}

void FileTree::obsolete() {
	root.obsolete();
}


void FileTree::buildTree(const char* rootFolderPath) {
	Folder* buildRoot = &root;
	BaseFile* data;
	for(FileIterator iter(rootFolderPath, filePattern); !iter.isFinished(); iter.nextFile()) {
		data = iter.getData();
		if (data != NULL) {
			File* newFile = dynamic_cast<File*>(data);
			Folder* newFolder = dynamic_cast<Folder*>(data);
			if(newFile) {
				buildRoot->addFile(*newFile);
			} else if(newFolder) {
				Folder* newlyInsertedFolder = buildRoot->addFolder(*newFolder);
				if(newlyInsertedFolder) {
					newlyInsertedFolder->setParent(buildRoot);
					buildRoot = newlyInsertedFolder;
				}
			} else {
				throw;
			}
		} else {
			buildRoot = &(buildRoot->getParent());
		}
	}
}

FileTree::FileTree(const char* rootFolderPath, const char* filePattern): 
			root(Folder(rootFolderPath)), filePattern(filePattern) {
	buildTree(rootFolderPath);
	normalize();
}

void FileTree::refresh() {
	obsolete();
	buildTree(root.getName());
}

void FileTree::print(const char* pattern) {
	char* iterationPath = NULL;
    dynamicStrCpy(iterationPath, root.getName());

	root.print(iterationPath, pattern);

	delete [] iterationPath;
}
