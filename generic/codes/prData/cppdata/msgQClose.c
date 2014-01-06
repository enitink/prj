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

    if (argc != 2) {
     fprintf(stderr, "Usage: %s <mq-name>\n", argv[0]);
     exit(EXIT_FAILURE);
    }

	int t_mq = mq_unlink(argv[1]);

   // pause();    /* Process will be terminated by thread function */
}
