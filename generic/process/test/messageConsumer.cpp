#include <iostream>

using namespace std;

#include <gMessageConsumer.h>
#include <gMessageQueue.h>

using namespace gen::common::process::messageQ; 
using namespace gen::common::process::messageConsumer;

class HelloMsgQ : public gMessageConsumer
{
private:
	gMessageQueue* __pMessageQ;
public:
	HelloMsgQ() { __pMessageQ = new gMessageQueue(this); __pMessageQ->init(); }
	~HelloMsgQ() { delete __pMessageQ; }
	virtual void* onMessage(char* ptr){ cout << ptr << endl;  ++count; return NULL; }
	virtual const char* messageQueueName(){ return "/HelloMsgQ"; }
};

int main()
{
	HelloMsgQ obj;
	return 0;
}
