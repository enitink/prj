#ifndef __COMMON_MESSAGE_QUEUE__
#define __COMMON_MESSAGE_QUEUE__

#include <mqueue.h>

#include <gThread.h>
#include <gMessageConsumer.h>

namespace gen { namespace common { namespace process { namespace messageQ {

using namespace gen::common::process::thread;
using namespace gen::common::process::messageConsumer;

class gMessageQueue
	:	public gThread
{
public:
	gMessageQueue(gMessageConsumer*);
	~gMessageQueue();

protected:
	virtual void*   run();

private:
	static void thFunc(union sigval sv);

private:
	mqd_t				__mqDesc;
	gMessageConsumer*	__pMessageConsumer;
};

}}}}
#endif //__COMMON_MESSAGE_QUEUE_
