#ifndef __COMMON_MESSAGE_QUEUE__
#define __COMMON_MESSAGE_QUEUE__

//#include <fcntl.h>           /* For O_* constants */
//#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>
#include <gMessageConsumer.h>

namespace gen { namespace common { namespace process { namespace messageQ {

using gen::common::process::messageConsumer::gMessageConsumer;

class gMessageQueue
{
public:
	gMessageQueue(gMessageConsumer*);
	~gMessageQueue();

private:
	static void thFunc(union sigval sv);

private:
	mqd_t				__mqDesc;
	gMessageConsumer*	__pMessageConsumer;
};

}}}}
#endif //__COMMON_MESSAGE_QUEUE_
