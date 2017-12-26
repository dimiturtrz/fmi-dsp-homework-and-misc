#include "FileTree.h"
#include "FileIterator.h"

#include "MyStrings.h"

FileTree::FileTree(const char* rootFolderPath): root(Folder(rootFolderPath)) {
	Folder* buildRoot = &root;
	BaseFile* data;
	for(FileIterator iter(rootFolderPath); !iter.isFinished(); iter.nextFile()) {
		data = iter.getData();
		if (data != NULL) {
			File* newFile = dynamic_cast<File*>(data);
			Folder* newFolder = dynamic_cast<Folder*>(data);
			if(newFile) {
				buildRoot->addFile(*newFile);
			} else if(newFolder) {
				newFolder->setParent(buildRoot);
				buildRoot->addFolder(*newFolder);
				buildRoot = &(buildRoot->getTopSubfolder());
			} else {
				throw;
			}
		} else {
			buildRoot = &(buildRoot->getParent());
		}
	}
}

void FileTree::refresh() {}

void FileTree::print(const char* pattern) {
	char* iterationPath = NULL;
    dynamicStrCpy(iterationPath, root.getName());

	root.print(iterationPath);

	delete [] iterationPath;
}
