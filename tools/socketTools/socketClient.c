#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define SOCKET_ADDR "127.0.0.1"
#define SOCKET_PORT  18888
#define MAXSIZE 1024

int main(){
    int sockfd;
    struct sockaddr_in sockaddr;

    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(SOCKET_PORT);
    sockaddr.sin_addr.s_addr = inet_addr(SOCKET_ADDR);

    char sendbuf[MAXSIZE];
    char recvbuf[MAXSIZE];
    
    while(1){ 
        memset(sendbuf, 0, sizeof(sendbuf));
        memset(recvbuf, 0, sizeof(recvbuf));
        sockfd = socket(AF_INET,SOCK_STREAM, 0);
        if(sockfd<0){
		    perror("socket");
		    exit(EXIT_FAILURE);
	    }
        printf("sockfd:%d\n",sockfd);
        if (connect(sockfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) < 0){
		    perror("connect");
    	    exit(EXIT_FAILURE);
        }

        //scanf("%s",sendbuf);
        fgets(sendbuf,MAXSIZE,stdin);//使用fgets可以连控制字符一起读

        //当前逻辑，每次发送后等待接收
        send(sockfd, sendbuf, strlen(sendbuf),0); ///发送
        if(strcmp(sendbuf,"exit\n")==0 || strcmp(sendbuf,"exit")==0)
            break;
        if(strcmp(sendbuf,"stop\n")==0 || strcmp(sendbuf,"stop")==0)
            break;
        recv(sockfd, recvbuf, sizeof(recvbuf),0); ///接收
        //fputs(recvbuf, stdout);
        printf("Client:%s\n",sendbuf);
        printf("Server:%s\n",recvbuf);
        close(sockfd);
    }
    
    return 0;
}
