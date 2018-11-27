#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>

#define SOCKET_ADDR "127.0.0.1"
#define SOCKET_PORT  18888
#define MAXSIZE 1024

int main()
{
    int sockfd = socket(AF_INET,SOCK_STREAM, 0);
    struct sockaddr_in sockaddr;

    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(SOCKET_PORT);
    sockaddr.sin_addr.s_addr = inet_addr(SOCKET_ADDR);

    int connfd;
    char sendbuf[MAXSIZE];
    char recvbuf[MAXSIZE];
    connfd=connect(sockfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr));
    if (connfd < 0){
		perror("connect");
    	exit(EXIT_FAILURE);
    }
    memset(sendbuf, 0, sizeof(sendbuf));
    memset(recvbuf, 0, sizeof(recvbuf));

    scanf("%s",sendbuf);

    send(sockfd, sendbuf, strlen(sendbuf),0); ///发送
    if(strcmp(sendbuf,"exit\n")==0 || strcmp(sendbuf,"exit")==0)
        ;//break;
    recv(sockfd, recvbuf, sizeof(recvbuf),0); ///接收
    //fputs(recvbuf, stdout);
    printf("Client:%s\n",sendbuf);
    printf("Server:%s\n",recvbuf);

    //close(connfd);
    close(sockfd);
    return 0;
}
