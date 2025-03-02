// SPDX-License-Identifier: GPL-3.0+ OR MIT
#include "PreRTS.h"
#include "Common/Debug.h"

#include <signal.h>

void ReleaseCrash(const char* reason)
{
  // TODO: Consider using libunwind or Google Breakpad to generate a stack trace
  // and write it to a file.

  // For now, just inform, that the game has crashed, via a message to stderr.
  fprintf(stderr, "The game has crashed: %s\n", reason);
  raise(SIGINT);
}

void ReleaseCrashLocalized(const AsciiString& strPrompt, const AsciiString& strMsg)
{
  ReleaseCrash(strMsg.str());
}