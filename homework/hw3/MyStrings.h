#include<iostream>

#ifndef MY_STRINGS
#define MY_STRINGS 

//standart
int strlen(const char* str);
void strcpy(char* destination, const char* source);
int strcmp(const char* str1, const char* str2);
void strcat(char* destination, const char* source);

//specific
void dynamicStrCpy(char*& destination, const char* source);

void appendComponentToPath(char*& path, const char* newComponent);
void removeLastComponentFromPath(char*& path);

#endif
