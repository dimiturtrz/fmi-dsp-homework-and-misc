#include "Patterns.h"

bool match(const char* str, const char* pattern) {
	switch(findPattern(pattern)) {
	case extension:
		return matchExtension(str, pattern);
	case regex:
		return matchRegex(str, pattern);
	}
}

PatternTypes findPattern(const char* pattern) {
	for(int i = 0; pattern[i] != '\0'; ++i) {
		if(pattern[i] == '.') {
			return regex;
		}
	}
	return extension;
}

bool matchExtension(const char* str, const char* pattern) {
	int strLen = strlen(str);

	int dotIndex = strLen - 1;
	for(; str[dotIndex] != '.'; --dotIndex);

	return (strcmp(str + dotIndex + 1, pattern) == 0);
}

bool matchRegex(const char* str, const char* pattern) {
	return true;
}
