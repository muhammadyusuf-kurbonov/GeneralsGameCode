#pragma once

// If on x86, define the following types
#if defined(_M_IX86) || defined(_M_X64)
#define CALLBACK __stdcall
#else
#define CALLBACK
#endif

static unsigned int GetDoubleClickTime()
{
  return 500;
}

#include "types_compat.h"

#include "thread_compat.h"
#include "tchar_compat.h"
#include "time_compat.h"
#include "string_compat.h"
#include "keyboard_compat.h"
#include "memory_compat.h"
#include "module_compat.h"
#include "wchar_compat.h"