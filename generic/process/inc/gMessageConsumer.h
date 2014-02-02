#ifndef __COMMON_MESSAGE_CONSUMER__
#define __COMMON_MESSAGE_CONSUMER__

namespace gen { namespace common { namespace process { namespace messageConsumer {

class gMessageConsumer
{
public:
	virtual void* onMessage(char* )= 0;
	virtual const char* messageQueueName()= 0; 
};

}}}}
#endif //__COMMON_MESSAGE_CONSUMER__
