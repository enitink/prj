#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while (0)
char* arg;

void*                     /* Thread start function */
tfunc(void* arg)
{
    struct mq_attr attr;
    ssize_t nr;
    void *buf;
    mqd_t mqdes = *((mqd_t*) arg);
	//printf(" %d \n", mqdes);

    /* Determine max. msg size; allocate buffer to receive msg */

    if (mq_getattr(mqdes, &attr) == -1)
        handle_error("mq_getattr");
    buf = malloc(attr.mq_msgsize);
    if (buf == NULL)
        handle_error("malloc");

	while(1){
		bzero(buf, attr.mq_msgsize);
		nr = mq_receive(mqdes, buf, attr.mq_msgsize, NULL);
		if (nr == -1)
				handle_error("mq_receive");

		//printf("Read %ld bytes from MQ\n", (long) nr);
		printf("%ld:%s\n", (long)nr, (char*)buf);
		if ( strncmp("exit", (char*)buf, 4) == 0) { 
				free(buf);
				return NULL;
		}
	}
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

	//printf(" %d \n", mqdes);

	mqdes = mq_open(argv[1], O_RDONLY);
    if (mqdes == (mqd_t) -1)
        handle_error("mq_open");

	pthread_t       _threadId;
	pthread_create(&_threadId, NULL, tfunc, &mqdes);
	pthread_join(_threadId, NULL);

	printf("closing and unlinking messageQ\n");
	mq_unlink(argv[1]);	
}
