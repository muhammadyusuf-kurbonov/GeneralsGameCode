#include <gtest/gtest.h>

#include "Lib/BaseType.h"
#include "Common/GameMemory.h"

#include "Common/UnicodeString.h"

TEST(Strings, Format)
{
  UnicodeString msgHello(L"Hello %s");
  UnicodeString msgWorld(L"World");

  UnicodeString msg;
  msg.format(msgHello, msgWorld.str());
  std::cout << msg.str() << std::endl;
  EXPECT_STREQ(msg.str(), L"Hello World");
}