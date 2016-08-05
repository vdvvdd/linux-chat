#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#include "msg.h"

#define SERVER_PORT 8888

void handle_client(int client_sockfd);
void send_client_contack_list(char *client_name, int client_sockfd, int type);
char *get_time();


int main(void)
{
    int sockfd;
    int client_sockfd;
    int len;

    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;

    pthread_t pthd;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket error");
        exit(0);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if ((bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr))) == -1)
    {
        perror("bind error");
        exit(0);
    }

    printf("running chat......\n");

    len = sizeof(struct sockaddr_in);

    while (1)
    {
        listen(sockfd, 5);
        if ((client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &len)) < 0)
        {
            perror("accept error");
            continue;
        }
        else
        {
            if (pthread_create(&pthd, NULL, (void *)handle_client, (int *)client_sockfd) != 0)
                perror("pthread_create error");
            pthread_detach(pthd);
        }
    }


    return 0;
}



void handle_client(int client_sockfd)
{}
