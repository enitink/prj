#include <gSemaphore.h>

namespace gen { namespace common { namespace process { namespace semaphore {

gSemaphore::gSemaphore()
	:	__semtype(SEM_TYPE_THREAD)
{}

gSemaphore::~gSemaphore()
{}

sem_t	gSemaphore::self()
{
	return __sem;
}

s32_t gSemaphore::init(gSemaphoretype_e lsem, u32_t lsize)
{
	__semtype = lsem;
	__semno = lsize;

	return sem_init(&__sem, __semtype, __semno);
}

s32_t	gSemaphore::post()
{}

s32_t	gSemaphore::wait()
{}

s32_t	gSemaphore::timedwait(u32_t lsec)
{
		struct timespec ts;
		if (clock_gettime(CLOCK_REALTIME, &ts) == -1)
				handle_error("clock_gettime");
		ts.tv_sec += lsec;

		return sem_timedwait(&__sem, &ts);
}

s32_t	gSemaphore::trywait(u32_t)
{}

gSemaphoretype_e	gSemaphore::getsemtype()
{}

}}}}
