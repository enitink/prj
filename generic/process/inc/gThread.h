#ifndef __COMMON_THREAD__
#define __COMMON_THREAD__

#include <pthread.h>

namespace gen { namespace common { namespace process { namespace thread {

class gThread
{
public:
					gThread();
	virtual			~gThread();
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

#endif //__COMMON_THREAD__
