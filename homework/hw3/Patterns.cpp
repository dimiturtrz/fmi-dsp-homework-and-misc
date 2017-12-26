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
		if(pattern[i] == '.' || pattern[i] == '?' || pattern[i] == '*') {
			return regex;
		}
	}
	return extension;
}

bool matchExtension(const char* str, const char* pattern) {
	int strLen = strlen(str);

	int dotIndex = strLen - 1;
	for(; dotIndex > 0 && str[dotIndex] != '.'; --dotIndex);

	return (strcmp(str + dotIndex + 1, pattern) == 0);
}

bool matchRegex(const char* str, const char* pattern) {
	if(str[0] != '\0' && pattern[0] != '\0') {
		if(pattern[0] == '*') {
            while(pattern[1] == '*') {
                return matchRegex(str, pattern + 1);
            }
			for(int strInd = 0; str[strInd] != '\0'; ++strInd) {
				if(matchRegex(str + strInd, pattern + 1)) {
					return true;
				}
			}
            return matchRegex("", pattern + 1);
		}

		if(pattern[0] != '?' && pattern[0] != str[0]) {
			return false;
		}
		return matchRegex(str + 1, pattern + 1);
	}
	return (str[0] == '\0' && pattern[0] == '\0');
}
