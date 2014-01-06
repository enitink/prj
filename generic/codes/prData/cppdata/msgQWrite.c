#include <pthread.h>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while (0)

int
main(int argc, char *argv[])
{
    mqd_t mqdes;
    struct sigevent sev;

    if (argc != 3) {
     fprintf(stderr, "Usage: %s <mq-name> <msg>\n", argv[0]);
     exit(EXIT_FAILURE);
    }


	mqdes = mq_open(argv[1], O_WRONLY);
    if (mqdes == (mqd_t) -1)
        handle_error("mq_open");

    if (mq_send(mqdes, argv[2], strlen(argv[2]), 5) == -1)
        handle_error("mq_send");
	mq_close(mqdes);	

   // pause();    /* Process will be terminated by thread function */
}
