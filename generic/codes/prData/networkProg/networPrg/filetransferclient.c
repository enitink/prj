#include 	<stdio.h>
#include 	<stdlib.h>
#include	<string.h>
#include	<sys/socket.h>
#include	<arpa/inet.h>
#include	<errno.h>

#define	MAXLINE		4096	/* max text line length */
#define	BUFFSIZE	8192	/* buffer size for reads and writes */
#define	SA		struct sockaddr

int
main(void){
	
	int i = 0;
	
	// Starting the server to recieve the data

	int			listenfd,connfd,n;
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
	servaddr.sin_port        = htons(7777);

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

	if((connfd = accept(listenfd, (SA *) NULL, NULL)) < 0){
		printf("Accept Error");
		exit(1);
	}

	char filename[100];
	printf("\nRequest to recieve file.. enter path/<file name> to save as : ");
	fgets(filename, 100, stdin);
	filename[strlen(filename) - 1] = 0;
	printf("filename: %s",filename);

	FILE *fp;
	fp = fopen(filename, "wb");

	if((n = write(connfd, "ack", strlen("ack"))) < 0){
		printf("write error");
		exit(1);
	}
	while ((n = read(connfd, recvline, MAXLINE)) > 0) {
		recvline[n] = 0;
		fputs(recvline, fp);
	}
	if (n < 0)
		printf("read error");
	
	printf("file saved\n");
	close(connfd);
	fclose(fp);
	
	exit(0);
}
