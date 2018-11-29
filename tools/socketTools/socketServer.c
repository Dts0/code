#include <stdio.h>	//perror,printf
#include <stdlib.h>	//exit
#include <sys/socket.h>	//socket,bind,listen,accept,send,recv
#include <netinet/in.h>	//struct sockaddr_in,htons
#include <arpa/inet.h>	//inet_addr
#include <unistd.h>	//close
#include <string.h>	//memset,strcmp

#define SOCKET_ADDR "127.0.0.1"
#define SOCKET_PORT 18888
#define MAXSIZE 1024


int main(){
	int sockfd;
	uint16_t port=18888;
	struct sockaddr_in sockaddr;

	sockfd=socket(AF_INET,SOCK_STREAM,0);//默认为TCP
	if(sockfd<0){
		perror("socket");
		exit(EXIT_FAILURE);
	}
	printf("sockfd:%d\n",sockfd);
	sockaddr.sin_family=AF_INET;
	sockaddr.sin_port=htons(port);
	sockaddr.sin_addr.s_addr=inet_addr(SOCKET_ADDR);
	if(bind(sockfd,(struct sockaddr*)&sockaddr,sizeof(sockaddr))<0){
		perror("bind");
		exit(EXIT_FAILURE);
	}
	if(listen(sockfd,MAXSIZE)<0){//最多接受MAXSIZE个连接
		perror("listen");
		exit(EXIT_FAILURE);
	}
	
	printf("waiting for client...\n");

	int connfd;
	int n;
	char buf[MAXSIZE];
	while(1){
		connfd=accept(sockfd,(struct sockaddr*)NULL,NULL);
		printf("connected,sockfd:%d\n",connfd);
		if(connfd<0){
			perror("accpet");
			continue;
		}
		memset(buf, 0, sizeof(buf));
		n=recv(connfd,buf,MAXSIZE,0);//接收最大MAXSIZE个字符
		if(strcmp(buf,"exit\n")==0 || strcmp(buf,"exit")==0)
            break;
		send(connfd,"ok!",3,0);//发送"ok!"
		printf("%d bytes from client:\n%s\n",n,buf);

		close(connfd);//关闭本连接
	}

	printf("closed\n");
	close(sockfd);//关闭监听端口
	//shutdown(connfd,SHUT_RDWR);
	//使用shutdown可以达到仅可读或仅可写
	
	return 0;
}

