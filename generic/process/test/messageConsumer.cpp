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
	int count;
public:
	HelloMsgQ() : count(0) { __pMessageQ = new gMessageQueue(this); }
	~HelloMsgQ() { delete __pMessageQ; }
	virtual void* onMessage(char* ptr){ cout << "inside HelloMsgQ" << ptr << endl;  ++count; if (count == 4) return NULL; }
	virtual const char* messageQueueName(){ return "/HelloMsgQ"; }
};

int main()
{
	HelloMsgQ obj;
	return 0;
}
