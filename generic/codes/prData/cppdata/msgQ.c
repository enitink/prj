#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while (0)

static void                     /* Thread start function */
tfunc(union sigval sv)
{
    struct mq_attr attr;
    ssize_t nr;
    void *buf;
    mqd_t mqdes = *((mqd_t *) sv.sival_ptr);

    /* Determine max. msg size; allocate buffer to receive msg */

    if (mq_getattr(mqdes, &attr) == -1)
        handle_error("mq_getattr");
    buf = malloc(attr.mq_msgsize);
    if (buf == NULL)
        handle_error("malloc");

	while (1){
	bzero(buf, attr.mq_msgsize);
    nr = mq_receive(mqdes, buf, attr.mq_msgsize, NULL);
    if (nr == -1)
        handle_error("mq_receive");

    printf("Read %ld bytes from MQ\n", (long) nr);
    printf("Read %s from MQ\n", (char*)buf);
		if (strncmp("exit",(char*)buf,4) == 0)
			break;
	}
    free(buf);
	mq_close(mqdes);	
    exit(EXIT_SUCCESS);         /* Terminate the process */
}

int
main(int argc, char *argv[])
{
    mqd_t mqdes;
    struct sigevent sev;

    if (argc != 2) {
     fprintf(stderr, "Usage: %s <mq-name>\n", argv[0]);
     exit(EXIT_FAILURE);
    }
	
	struct mq_attr* t_attr = NULL;
    mqdes = mq_open(argv[1], O_CREAT, S_IRWXU, t_attr);//__pMessageConsumer->messageQueueName(), O_RDONLY);
    if (mqdes == (mqd_t) -1)
        handle_error("mq_open");
	mq_close(mqdes);	

    mqdes = mq_open(argv[1], O_RDONLY);
    if (mqdes == (mqd_t) -1)
        handle_error("mq_open");
	
	printf(" %d \n", mqdes);

    //sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_notify = SIGEV_THREAD;
    sev.sigev_notify_function = tfunc;
    sev.sigev_notify_attributes = NULL;
    sev.sigev_value.sival_ptr = &mqdes;   /* Arg. to thread func. */
    if (mq_notify(mqdes, &sev) == -1)
        handle_error("mq_notify");

    pause();    /* Process will be terminated by thread function */
}

