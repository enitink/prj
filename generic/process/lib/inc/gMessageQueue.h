#ifndef __COMMON_MESSAGE_QUEUE__
#define __COMMON_MESSAGE_QUEUE__

#include <mqueue.h>
#include <pthread.h>

#include <gMessageConsumer.h>

namespace gen { namespace common { namespace ipc { namespace messageQ {

using namespace gen::common::process::messageConsumer;

class gMessageQueue
{
public:
	gMessageQueue(gMessageConsumer*);
	~gMessageQueue();
	bool			init();

private:
	static	void* 	threadInterface(void* arg);
	void*			run();
	bool			start();
	bool			join();
	bool			detach();

private:
	mqd_t				__mqDesc;
	pthread_t			__threadId;
	gMessageConsumer*	__pMessageConsumer;
};

}}}}

#endif //__COMMON_MESSAGE_QUEUE_
