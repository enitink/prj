#ifndef __COMMON_SEMAPHORE__
#define __COMMON_SEMAPHORE__

#include <pthread.h>

namespace gen { namespace common { namespace process { namespace semaphore {

typedef enum 
{
	SEM_TYPE_THREAD,
	SEM_TYPE_PROCESS
}gSemaphoretype_e;

template <class T>
class gSemaphore
{
protected:
				gSemaphore();
	virtual		~gSemaphore();

	sem_t		self();

	s32_t		init(gSemaphoretype_e, u32_t);
	s32_t		post();
	s32_t		wait();
	s32_t		timedwait(u32_t);
	s32_t		trywait(u32_t);

	gSemaphoretype_e	getsemtype();
private:
	sem_t 				__sem;
	gSemaphoretype_e	__semtype;
	u32_t				__semno;
};

}}}}

#endif //__COMMON_SEMAPHORE__
