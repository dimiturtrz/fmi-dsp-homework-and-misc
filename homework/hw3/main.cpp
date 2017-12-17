#include <dirent.h>
#include <iostream>

#include "MyStrings.h"

#define MY_MAX_PATH 260 

void appendToPath(char* path, const char* newComponent) {
	int len = strlen(path);
	path[len] = '/';
	path[len + 1] = '\0';
	strcat(path, newComponent);
}

void removeLastComponent(char* path) {
	int len = strlen(path);
	for(; path[len] != '/' && len > 0; --len);
	path[len] = '\0';
}

void listDir(char* path){
	DIR* dir;
	struct dirent *ent;
	if((dir = opendir(path)) != NULL){
		while ((ent = readdir(dir)) != NULL){
			if(strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
				continue;
			}

			switch(ent->d_type) {
			case DT_DIR:
				std::cout<< "dir: "<< ent->d_name<< std::endl;
				appendToPath(path, ent->d_name);
				listDir(path);
				removeLastComponent(path);
				break;
			case DT_REG:
				std::cout<< "file: "<< ent->d_name<< std::endl;
				break;
			default:
				std::cout<< "other: "<< ent->d_type<< std::endl;
				break;
			}
		}
		closedir(dir);
  }
}

int main(){
	char path[MY_MAX_PATH] = "..";

	listDir(path);
	return 0;
}
