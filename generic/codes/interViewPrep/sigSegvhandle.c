/* A C program that does not terminate when Ctrl+C is pressed */
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

/* Signal Handler for SIGINT */
void sigintHandler(int sig_num)
{
	/* Reset handler to catch SIGINT next time.
	   Refer http://en.cppreference.com/w/c/program/signal */
	signal(SIGSEGV, sigintHandler);
	printf("\n Cannot be terminated by SIGSEGV\n");
	//fflush(stdout);
	exit(0);
}

int main ()
{
	/* Set the SIGINT (Ctrl-C) signal handler to sigintHandler
	   Refer http://en.cppreference.com/w/c/program/signal */
//	signal(SIGSEGV, sigintHandler);

	int *j = 0, i; 
	/* Infinite loop */
	while(1)
	{      
		scanf("%d", &i);
		printf("%d", *j);
	}
	return 0;
}
