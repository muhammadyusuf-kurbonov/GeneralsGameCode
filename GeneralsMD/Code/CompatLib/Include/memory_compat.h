#pragma once

#include <stdlib.h>

#define GMEM_FIXED 0

static void *GlobalAlloc(int, size_t size)
{
  return malloc(size);
}

static void GlobalFree(void *ptr)
{
  free(ptr);
}