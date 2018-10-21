#ifndef __COMMON_THREAD_POOL_
#define __COMMON_THREAD_POOL_

#include <pthread.h>

namespace gen { namespace common { namespace process { namespace thread {

class gThreadPool
{
public:
				gThreadPool();
	virtual			~gThreadPool();
	bool			init();

protected:
	pthread_t		self();
	virtual void*	run() = 0;

protected:
	pthread_t		_threadId;

private:
	static	void* 	threadInterface(void* arg);
	bool			start();
	bool			join();
	bool			detach();
};

}}}}

#endif //__COMMON_THREAD_POOL_
