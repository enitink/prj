#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while (0)

char* arg;
	
void addNotify();

static void                     /* Thread start function */
tfunc(union sigval sv)
{
    struct mq_attr attr;
    ssize_t nr;
    void *buf;
    mqd_t mqdes = ((mqd_t) sv.sival_ptr);
	printf(" %d \n", mqdes);

    /* Determine max. msg size; allocate buffer to receive msg */

    if (mq_getattr(mqdes, &attr) == -1)
        handle_error("mq_getattr");
    buf = malloc(attr.mq_msgsize);
    if (buf == NULL)
        handle_error("malloc");

	bzero(buf, attr.mq_msgsize);
    nr = mq_receive(mqdes, buf, attr.mq_msgsize, NULL);
    if (nr == -1)
        handle_error("mq_receive");

    printf("Read %ld bytes from MQ\n", (long) nr);
    printf("Read %s from MQ\n", (char*)buf);
	mq_close(mqdes);	
   	if ( strncmp("exit", (char*)buf, 4) == 0) { 
	free(buf);
    exit(EXIT_SUCCESS);         /* Terminate the process */
	}
	addNotify();
}

void addNotify()
{
    printf("adding notification \n");
    mqd_t mqdes = mq_open(arg, O_RDONLY);
    if (mqdes == (mqd_t) -1)
        handle_error("mq_open");
    struct sigevent sev;
    sev.sigev_notify = SIGEV_THREAD;
    sev.sigev_notify_function = tfunc;
    sev.sigev_notify_attributes = NULL;
    sev.sigev_value.sival_ptr = (void *)mqdes;   /* Arg. to thread func. */
    if (mq_notify(mqdes, &sev) == -1)
        handle_error("mq_notify");
}

int
main(int argc, char *argv[])
{
    mqd_t mqdes;

    if (argc != 2) {
     fprintf(stderr, "Usage: %s <mq-name>\n", argv[0]);
     exit(EXIT_FAILURE);
    }
	
	struct mq_attr* t_attr = NULL;
    mqdes = mq_open(argv[1], O_CREAT, S_IRWXU, t_attr);//__pMessageConsumer->messageQueueName(), O_RDONLY);
    if (mqdes == (mqd_t) -1)
        handle_error("mq_open");
	mq_close(mqdes);	

	
	printf(" %d \n", mqdes);
	arg = argv[1];
	addNotify(mqdes);

    pause();    /* Process will be terminated by thread function */
}
