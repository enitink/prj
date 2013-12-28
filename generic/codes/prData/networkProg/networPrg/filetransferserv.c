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
main(int argc, char **argv){
	
	int i = 0;
	char * filename = NULL;
	
	if(argc != 2){
		printf("\nwhat's with you idiot.. where do I will talk with the system");
		printf("\ngive me.. something like this... : a.out <ip address>:<filename>");
		printf("\nrun me again you dumbo....\n");
		exit(1);
	}
	else {
		for(	; i < strlen(argv[1]); ++i){
			if(argv[1][i] == ':'){
				argv[1][i] = '\0';
				filename = &argv[1][i + 1];
				break;
			}
		}
	}
	if(filename == NULL){
		printf("File read error");
		exit(1);
	}
	
	// Getting connected to the reciever and checking for acknowlegdement....

	int			sockfd,n;
	struct sockaddr_in	servaddr;
	char			recvline[MAXLINE + 1];

	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		printf("socket error\n");
		exit(1);
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port   = htons(7777);	

	if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0){
		printf("inet_pton error for %s\n", argv[1]);
		exit(1);
	}

	if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0){
		printf("connect error\n");
		exit(1);
	}	
	
	n = read(sockfd, recvline, MAXLINE);
	if(n > 0){
		recvline[n] = 0;	/* null terminate */
		if(strcmp(recvline, "ack") != 0){
			printf("Acknowledgment Error\n");
			exit(1);
		}
	}

	
	FILE * fp;
	fp = fopen(filename, "rb");
	char	buff[BUFFSIZE];
	printf("\ngoing to write into file...");
	
	while(fgets(buff, BUFFSIZE, fp) != NULL){
		if((n = write(sockfd, buff,strlen(buff))) < 0){
			printf("write error");
			exit(1);
		}
	}

	printf("\n File sent\n");
	
	close(sockfd);
	
	exit(0);
}
