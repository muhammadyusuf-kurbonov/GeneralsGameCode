#pragma once

#include <stdint.h>

typedef void *HANDLE;
typedef HANDLE HWND;
typedef HANDLE HINSTANCE;
typedef HANDLE HKEY;
typedef int32_t HRESULT;

typedef int BOOL;
typedef unsigned char BYTE;

#define INVALID_HANDLE_VALUE NULL

typedef void *LPVOID;

#define FALSE 0
#define TRUE 1

#define S_OK 0

// Microsoft direction specifiers, used purely for documentation purposes
#define IN
#define OUT