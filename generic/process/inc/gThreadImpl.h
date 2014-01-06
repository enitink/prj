#ifndef __COMMON_THREAD_IMPL__
#define __COMMON_THREAD_IMPL__

namespace gen { namespace common { namespace process { namespace threadImpl {

class gThreadImpl
{
public:
					gThreadImpl(){};
	virtual			~gThreadImpl(){};

	virtual void* runChild()=0;
};

}}}}

#endif //__COMMON_THREAD_IMPL__
