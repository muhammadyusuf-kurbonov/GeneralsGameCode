#pragma once

#include <pthread.h>
typedef pthread_t THREAD_ID;

THREAD_ID GetCurrentThreadId();