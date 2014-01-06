#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <gMessageQueue.h>

#define handle_error(msg) \
		do { perror(msg); exit(EXIT_FAILURE); } while (0)

using namespace std;

namespace gen { namespace common { namespace process { namespace messageQ {

void gMessageQueue::thFunc(union sigval sv)
{
	struct mq_attr attr;
    ssize_t nr;
    void *buf;
    gMessageQueue* gMsgQ = (gMessageQueue*) sv.sival_ptr;

	mqd_t mqdes = gMsgQ->__mqDesc;
    /* Determine max. msg size; allocate buffer to receive msg */

    if (mq_getattr(mqdes, &attr) == -1)
        handle_error("mq_getattr");
    buf = malloc(attr.mq_msgsize);
    if (buf == NULL)
        handle_error("malloc");

    while (1){
		bzero(buf, attr.mq_msgsize);
		nr = mq_receive(mqdes, (char*)buf, attr.mq_msgsize, NULL);
		if (nr == -1)
		    handle_error("mq_receive");
		
		if ( (gMsgQ->__pMessageConsumer->onMessage( (char*) buf)) == NULL)
			break;
    }
    free(buf);
    mq_close(mqdes);
	exit(0);
}

gMessageQueue::gMessageQueue(gMessageConsumer* ptr) : __pMessageConsumer(ptr)
{
	struct mq_attr* t_attr = NULL;
	__mqDesc = mq_open(__pMessageConsumer->messageQueueName(), O_CREAT, S_IRWXU, t_attr);//__pMessageConsumer->messageQueueName(), O_RDONLY);
	if (__mqDesc == (mqd_t) -1)
        handle_error("mq_open");
    
	mq_close(__mqDesc);

	struct sigevent sev;
	sev.sigev_notify = SIGEV_THREAD;
    sev.sigev_notify_function = &(gMessageQueue::thFunc);
    sev.sigev_notify_attributes = NULL;
    sev.sigev_value.sival_ptr =  this; /* Arg. to thread func. */
   
	__mqDesc = mq_open(__pMessageConsumer->messageQueueName(), O_RDONLY);
    if (__mqDesc == (mqd_t) -1)
        handle_error("mq_open");
 
	if (mq_notify(__mqDesc, &sev) == -1)
        handle_error("mq_notify");

	pause();
}

gMessageQueue::~gMessageQueue()
{
	int t_mq = mq_unlink(__pMessageConsumer->messageQueueName());
}

}}}}
