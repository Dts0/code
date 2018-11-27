#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>	//memset

#define SOCKET_ADDR "127.0.0.1"
#define SOCKET_PORT 18888
#define MAXSIZE 1024


int main(){
	int sockfd;
	uint16_t port=18888;
	struct sockaddr_in sockaddr;

	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0){
		perror("socket");
		exit(EXIT_FAILURE);
	}

	sockaddr.sin_family=AF_INET;
	sockaddr.sin_port=htons(port);
	sockaddr.sin_addr.s_addr=inet_addr(SOCKET_ADDR);
	if(bind(sockfd,(struct sockaddr*)&sockaddr,sizeof(sockaddr))<0){
		perror("bind");
		exit(EXIT_FAILURE);
	}
	if(listen(sockfd,MAXSIZE)<0){
		perror("listen");
		exit(EXIT_FAILURE);
	}
	
	printf("waiting for client...\n");

	int connfd;
	int n;
	char buf[MAXSIZE];
	while(1){
		connfd=accept(sockfd,(struct sockaddr*)NULL,NULL);
		if(connfd<0){
			perror("accpet");
			continue;
		}
		memset(buf, 0, sizeof(buf));
		n=recv(connfd,buf,MAXSIZE,0);
		if(strcmp(buf,"exit\n")==0 || strcmp(buf,"exit")==0)
            break;
		send(connfd,"ok!",3,0);
		printf("%d bytes from client:\n%s\n",n,buf);

		close(connfd);
	}

	close(sockfd);
	//shutdown(connfd,SHUT_RDWR);

	
	return 0;
}

