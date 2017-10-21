#include "MyStrings.h"

int strlen(const char* str) {
	int i = 0;
	for(; str[i] != '\0'; ++i);
	return i;
}

void strcpy(char* destination, const char* source) {
	for(int i=0; source[i] != '\0'; i++) {
		destination[i] = source[i];
	}
	destination[strlen(source)] = '\0';
}

int strcmp(const char* str1, const char* str2) {
	if(strlen(str1) == strlen(str2)) {
		for(int i=0; str1[i] != '\0'; i++) {
			if(str1[i] == str2[i]) {
				continue;
			} else {
				return (str1[i] > str2[i]) ? 1 : -1;
			}
		}
		return 0;
	}
	return (strlen(str1) > strlen(str2)) ? 1 : -1;
}
