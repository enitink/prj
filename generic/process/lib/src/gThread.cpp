#include <iostream>
#include <gThread.h>

using namespace std;

namespace gen { namespace common { namespace process { namespace thread {

void* gThread::threadInterface(void* gArg)
{
	gThread* arg = (gThread*)gArg;
	return (arg->run());
}

gThread::gThread() {}

gThread::~gThread()
{
}

bool gThread::init()
{
	start();
	join();
	return true;
}

bool gThread::start()
{
	pthread_create(&_threadId, NULL, &(gThread::threadInterface), this);
	return true;
}

bool gThread::join()
{
	pthread_join(_threadId, NULL);
	return true;
}

bool gThread::detach()
{
	pthread_detach(_threadId);
	return true;
}

pthread_t gThread::self()
{
	return _threadId;
}

}}}}
