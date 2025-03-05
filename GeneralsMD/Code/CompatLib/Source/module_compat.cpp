#include "types_compat.h"
#include "module_compat.h"

#include <unistd.h>

bool GetModuleFileName(HINSTANCE hInstance, char* buffer, int size)
{
  ssize_t count = readlink("/proc/self/exe", buffer, size);
  if (count == -1)
    return false;
  buffer[count] = '\0';
  return true;
}