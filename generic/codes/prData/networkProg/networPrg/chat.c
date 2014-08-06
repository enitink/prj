#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<pthread.h>
#include	<string.h>
#include	<sys/socket.h>
#include	<arpa/inet.h>
#include	<errno.h>

#define	MAXLINE		4096	/* max text line length */
#define	BUFFSIZE	8192	/* buffer size for reads and writes */
#define	SA		struct sockaddr

void server(void){
	int			listenfd, connfd,n;
	struct sockaddr_in	servaddr;
	char			recvline[MAXLINE + 1];
	
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if(listenfd < 0){
		printf("Socket Error");
		exit(1);
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family      = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port        = htons(7778);

	n = bind(listenfd, (SA *) &servaddr, sizeof(servaddr));
	if(n < 0){
		printf("Bind Error: Port in Use");
		exit(1);
	}

	n = listen(listenfd, 1024); 	// 1024 here is The backlog argument provides a hint to the implementation 
					// which the implementation shall use to limit the number of outstanding 
					// connections in the socket's listen queue. 

	if(n < 0){
		printf("Listening error");
		exit(1);
	}

	for ( ; ; ) {
		if((connfd = accept(listenfd, (SA *) NULL, NULL)) < 0){
			printf("Accept Error");
			exit(1);
		}
		
		while ((n = read(connfd, recvline, MAXLINE)) > 0) {
			recvline[n] = 0;
			printf("\nFriend : ");
			if (fputs(recvline, stdout) == EOF)
				printf("fputs error");
			printf("\nME: ");	
		}
		if (n < 0)
			printf("read error");
		close(connfd);
	}
}

void client(char *argv, char *arg){
	int			sockfd, n;
	char			buff[MAXLINE];
	struct sockaddr_in	servaddr;

	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		printf("socket error");
		exit(1);
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port   = htons(7777);	

	if (inet_pton(AF_INET, argv, &servaddr.sin_addr) <= 0){
		printf("inet_pton error for %s", argv);
		exit(1);
	}

	if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0){
		printf("connect error");
		exit(1);
	}

	snprintf(buff, sizeof(buff), "%s", arg);
	
	if((n = write(sockfd, buff, strlen(buff))) < 0){
		printf("write error");
		exit(1);
	}

	close(sockfd);
}

int
main(int argc, char **argv){
	
	pthread_t 	thread;
	int  		iret;
	char 		buff[MAXLINE];

	if(argc != 2){
		printf("\nwhat's with you idiot.. where do I will talk with the system");
		printf("\ngive me.. something like this... : a.out <ip address>");
		printf("\nrun me again you dumbo....\n");
		exit(1);
	}

	iret = pthread_create( &thread, NULL, (void *) server, NULL);
	
	printf("if you think.. you have to say anything.... then say buddy... \n");
	while(1){
		printf("\nME: ");	
		fgets(buff, MAXLINE, stdin);
		client(argv[1] , buff);
	}

	exit(0);
}
