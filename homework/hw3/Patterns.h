#include "MyStrings.h"

#ifndef PATTERNS
#define PATTERNS

enum PatternTypes { extension, regex };

bool match(const char* str, const char* pattern);
PatternTypes findPattern(const char* pattern);

bool matchExtension(const char* str, const char* pattern);
bool matchRegex(const char* str, const char* pattern);

#endif
