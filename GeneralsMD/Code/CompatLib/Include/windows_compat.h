#pragma once

// If on x86, define the following types
#if defined(_M_IX86) || defined(_M_X64)
#define CALLBACK __stdcall
#else
#define CALLBACK
#endif

#if !defined _MSC_VER
#if !defined(__cdecl)
#if defined __has_attribute && __has_attribute(cdecl) && defined(__i386__)
#define __cdecl __attribute__((cdecl))
#else
#define __cdecl
#endif
#endif /* !defined __cdecl */
#endif

#ifndef __forceinline
#if defined __has_attribute && __has_attribute(always_inline)
#define __forceinline __attribute__((always_inline))
#else
#define __forceinline inline
#endif
#endif

static unsigned int GetDoubleClickTime()
{
  return 500;
}

#include "types_compat.h"

#ifndef _lrotl
static inline uint32_t _lrotl(uint32_t value, int shift)
{
#ifdef __clang__
	return __builtin_rotateleft32(value, shift);
#else
	return ((value << shift) | (value >> (32 - shift)));
#endif
}
#endif

#include "thread_compat.h"
#include "tchar_compat.h"
#include "time_compat.h"
#include "string_compat.h"
#include "keyboard_compat.h"
#include "memory_compat.h"
#include "module_compat.h"
#include "wchar_compat.h"