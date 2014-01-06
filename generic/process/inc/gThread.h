#ifndef __COMMON_THREAD__
#define __COMMON_THREAD__

#include <pthread.h>
#include <gThreadImpl.h>

namespace gen { namespace common { namespace process { namespace thread {

using namespace gen::common::process::threadImpl;

class gThread
{
public:
					gThread(gThreadImpl*);
	virtual			~gThread();

protected:
	pthread_t		self();
protected:
	pthread_t		_threadId;
	gThreadImpl* 	_pThreadImpl;

private:
	static	void* 	threadInterface(void* arg);
	void*			run();
	bool			start();
	bool			join();
	bool			detach();
};

}}}}

#endif //__COMMON_THREAD__
