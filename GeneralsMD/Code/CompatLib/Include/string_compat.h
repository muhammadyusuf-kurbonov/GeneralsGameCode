#pragma once

#include <stddef.h>
#include <stdarg.h>

typedef const char* LPCSTR;
typedef char* LPSTR;

char* itoa(int value, char* str, int base);

int _vsnwprintf(wchar_t* buffer, size_t count, const wchar_t* format, va_list args);
#define _vsnprintf vsnprintf
char* strlwr(char* str);
#define _strlwr strlwr

#define lstrcmpi strcasecmp
#define _stricmp strcasecmp
#define stricmp strcasecmp
#define _strnicmp strncasecmp
#define strnicmp strncasecmp