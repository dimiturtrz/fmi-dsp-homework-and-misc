#include <dirent.h>
#include <iostream>
#include <cstring>

void listDir(const char* path){
DIR* dir;
struct dirent *ent;
  if((dir=opendir(path)) != NULL){
    while (( ent = readdir(dir)) != NULL){
      if(ent->d_type == DT_DIR && strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0){
        std::cout<< ent->d_name<< std::endl;
        listDir(ent->d_name);
      }
    }
    closedir(dir);
  }
}

int main(){
  listDir(".");
  return 0;
}
