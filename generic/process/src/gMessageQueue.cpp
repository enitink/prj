#include <iostream>
#include <cstdio>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>

#include <gMessageQueue.h>

using namespace std;

#define handle_error(msg) \
		do { perror(msg); exit(EXIT_FAILURE); } while (0)

namespace gen { namespace common { namespace process { namespace messageQ {

using namespace gen::common::process::messageConsumer;

void* gMessageQueue::threadInterface(void* gArg)
{
	gMessageQueue* arg = (gMessageQueue*)gArg;
	return (arg->run());
}

//void gMessageQueue::thFunc(union sigval sv)
void* gMessageQueue::run()
{
    __mqDesc = mq_open(__pMessageConsumer->messageQueueName(), O_RDONLY);
    if (__mqDesc == (mqd_t) -1)
        handle_error("mq_open");
    
	struct mq_attr attr;
    ssize_t nr;
    void *buf;
    
    if (mq_getattr(__mqDesc, &attr) == -1)
        handle_error("mq_getattr");
    buf = malloc(attr.mq_msgsize);
    if (buf == NULL)
        handle_error("malloc");

    while(1){
        bzero(buf, attr.mq_msgsize);
        nr = mq_receive(__mqDesc, (char*)buf, attr.mq_msgsize, NULL);
        if (nr == -1)
                handle_error("mq_receive");
    	
        if ( strncmp("exit", (char*)buf, 4) == 0) {
                free(buf);
				break;
        }
		__pMessageConsumer->onMessage( (char*)buf);
    }
    return NULL;
}

gMessageQueue::gMessageQueue(gMessageConsumer* ptr) : __pMessageConsumer(ptr)
{
	struct mq_attr* t_attr = NULL;
	__mqDesc = mq_open(__pMessageConsumer->messageQueueName(), O_CREAT, S_IRWXU, t_attr);//__pMessageConsumer->messageQueueName(), O_RDONLY);
	if (__mqDesc == (mqd_t) -1)
        handle_error("mq_open");

    mq_close(__mqDesc);
}

gMessageQueue::~gMessageQueue()
{
	cout << __pMessageConsumer->messageQueueName() << endl;
	join();
	int t_mq = mq_unlink(__pMessageConsumer->messageQueueName());
}

bool gMessageQueue::init()
{
	start();
	return true;
}

bool gMessageQueue::start()
{
	pthread_create(&__threadId, NULL, &(gMessageQueue::threadInterface), this);
	return true;
}

bool gMessageQueue::join()
{
	pthread_join(__threadId, NULL);
	return true;
}

bool gMessageQueue::detach()
{
	pthread_detach(__threadId);
	return true;
}

}}}}
