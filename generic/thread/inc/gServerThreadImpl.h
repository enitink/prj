#ifndef __Server_ThreadImpl__
#define __Server_ThreadImpl__

#include "gThread.h"

class gServerThreadImpl : public gThread
{
public:
	static 	void* 	threadInterface(void* arg);
public:
	gServerThreadImpl();
	void* run();
};
#endif //__Server_ThreadImpl__
