#include "string_compat.h"

#include <sstream>
#include <streambuf>
#include <ostream>

char* itoa(int value, char* str, int base)
{
  // Create stringbuf from str
  std::stringbuf buf;
  buf.pubsetbuf(str, 32);
  std::ostream os(&buf);
  os << value;
  // Null terminate, just in case
  str[32] = '\0';
  return str;
}

int _vsnwprintf(wchar_t* buffer, size_t count, const wchar_t* format, va_list args)
{
  std::wstring format_fixup(format);

  // Replace all %s with %ls
  size_t pos = format_fixup.find(L"%s", 0);
  while (pos != std::wstring::npos)
  {
    format_fixup.replace(pos, 3, L"%ls");
    pos += 3;
    pos = format_fixup.find(L"%s", pos);
  }


  return vswprintf(buffer, count, format_fixup.c_str(), args);
}

// Also defined in GameSpy gsplatformutil
__attribute__((weak))
char* _strlwr(char* str)
{
  for (int i = 0; str[i] != '\0'; i++)
  {
    str[i] = tolower(str[i]);
  }
  return str;
}