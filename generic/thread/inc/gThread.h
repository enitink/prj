#ifndef __gThread__
#define __gThread__

#include <pthread.h>

class gThread
{
public:
	gThread(void *(*thread_interface) (void *));
	virtual 	~gThread();
	//static 	void* 	threadInterface(void* arg);
	
protected:
	pthread_t	self();

private:
	bool		start(void *(*thread_interface) (void *));
	bool		join();
	bool		detach();
	
private:
	pthread_t	m_threadId;
};

#endif //__gThread__
