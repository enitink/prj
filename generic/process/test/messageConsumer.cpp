#include <iostream>

using namespace std;

#include <gMessageConsumer.h>
#include <gMessageQueue.h>

using namespace gen::common::ipc::messageQ; 
using namespace gen::common::process::messageConsumer;

class HelloMsgQ : public gMessageConsumer
{
private:
	gMessageQueue* __pMessageQ;
public:
	HelloMsgQ() { /*cout << "HelloMsgQ" << endl;*/ __pMessageQ = new gMessageQueue(this); __pMessageQ->init(); }
	~HelloMsgQ() { /*cout << "HelloMsgQ Des" << endl;*/ delete __pMessageQ; }
	virtual void* onMessage(char* ptr){ cout << ptr << endl;  return NULL; }
	virtual const char* messageQueueName(){ return "/HelloMsgQ"; }
};

class HelloMsgQ1 : public gMessageConsumer
{
private:
	gMessageQueue* __pMessageQ;
public:
	HelloMsgQ1() { /*cout << endl << "HelloMsgQ1";*/  __pMessageQ = new gMessageQueue(this); __pMessageQ->init(); }
	~HelloMsgQ1() { /*cout << endl << "HelloMsgQ1 des";*/  delete __pMessageQ; }
	virtual void* onMessage(char* ptr){ cout << ptr << endl;  return NULL; }
	virtual const char* messageQueueName(){ return "/HelloMsgQ1"; }
};

class HelloMsgQ2 : public gMessageConsumer
{
private:
	gMessageQueue* __pMessageQ;
public:
	HelloMsgQ2() { /*cout << endl << "HelloMsgQ1";*/  __pMessageQ = new gMessageQueue(this); __pMessageQ->init(); }
	~HelloMsgQ2() { /*cout << endl << "HelloMsgQ1 des";*/  delete __pMessageQ; }
	virtual void* onMessage(char* ptr){ cout << ptr << endl;  return NULL; }
	virtual const char* messageQueueName(){ return "/HelloMsgQ2"; }
};

int main()
{
	HelloMsgQ obj;
	HelloMsgQ1 ob2;
	HelloMsgQ2 ob3;
	
	return 0;
}
