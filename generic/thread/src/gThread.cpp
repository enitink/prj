#include <gThread.h>
#include <iostream>

using namespace std;

/*void* gThread::threadInterface(void* arg)
{
	return ((gThread*)arg)->run();
}*/

gThread::gThread(void *(*thread_interface) (void *))
{
	start(thread_interface);
	join();	
}

gThread::~gThread()
{
	detach();
}

bool gThread::start(void *(*thread_interface) (void *))
{
	pthread_create(&m_threadId, NULL, thread_interface, this);
	return true;
}

bool gThread::join()
{
	pthread_join(m_threadId, NULL);
	return true;
}

bool gThread::detach()
{
	pthread_detach(m_threadId);
	return true;
}

pthread_t gThread::self()
{
	return m_threadId;
}
