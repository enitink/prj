#include <iostream>
#include <cstdio>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <gServerThreadImpl.h>
#include <cstring>

#define	MAXLINE		4096	/* max text line length */
#define	BUFFSIZE	8192	/* buffer size for reads and writes */
#define	SA		struct sockaddr

using std::cout;
using std::endl;

gServerThreadImpl::gServerThreadImpl()
	: Thread(threadInterface)
{
}
void* gServerThreadImpl::run()
{
	int                 listenfd, connfd, n;
	struct sockaddr_in  servaddr;
	char                buff[MAXLINE];
	time_t              ticks;

	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	
	servaddr.sin_family      = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port        = htons(7778);   /* daytime server */

	n = bind(listenfd, (SA *) &servaddr, sizeof(servaddr));
	if(n < 0){
		cout << "Bind Error: Port in Use";
		return NULL; 
	}

	n = listen(listenfd, 1024); 	// 1024 here is The backlog argument provides a hint to the implementation 
					// which the implementation shall use to limit the number of outstanding 
					// connections in the socket's listen queue. 

	if(n < 0){
		cout << "Listening error";
		return NULL;
	}

	int counter = 0;
	for ( ; ; ) {
		++counter;
		cout << "Request No. : " << counter;
		if((connfd = accept(listenfd, (SA *) NULL, NULL)) < 0){
			cout << "Accept Error";
			return NULL;
		}

		ticks = time(NULL);
		snprintf(buff, sizeof(buff), "%.24s by Nitin\r\n", ctime(&ticks));
		if((n = write(connfd, buff, strlen(buff))) < 0){
			printf("write error");
			return NULL;
		}

		close(connfd);
	}	
	return NULL;
}

void* gServerThreadImpl::threadInterface(void* arg)
{
	return ((gServerThreadImpl*)arg)->run();
}
