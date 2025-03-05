#include "thread_compat.h"

THREAD_ID GetCurrentThreadId()
{
	pthread_t thread_id = pthread_self();
	return thread_id;
}