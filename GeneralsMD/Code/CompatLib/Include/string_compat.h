#pragma once

#include <stddef.h>
#include <stdarg.h>

typedef const char* LPCSTR;
typedef char* LPSTR;

char* itoa(int value, char* str, int base);

int _vsnwprintf(wchar_t* buffer, size_t count, const wchar_t* format, va_list args);
#define _vsnprintf vsnprintf