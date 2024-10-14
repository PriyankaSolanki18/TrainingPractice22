#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
 
#define PORT 15608 // The port users will connect to
 
void* handle_client(void* arg);
void readstring(int, char *);
 
int main(int C, char *V[]) {
    int socketfd, connectionsocket;
    struct sockaddr_in serveraddress, clientaddr;
    int binderror;
    socklen_t len;
    char buffer[100];
 
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0) {
        perror("socket");
        exit(1);
    }
 
    memset(&serveraddress, 0, sizeof(serveraddress));
    serveraddress.sin_family = AF_INET;
    serveraddress.sin_port = htons(PORT);
    serveraddress.sin_addr.s_addr = htonl(INADDR_ANY);
 
    binderror = bind(socketfd, (struct sockaddr *)&serveraddress, sizeof(serveraddress));
    if (binderror == -1) {
        perror("BIND!!!");
        exit(1);
    }
    listen(socketfd, 5);
 
    // Main server processing loop
    for (;;) {
        printf("Server: I am waiting---Start of Main Loop\n");
 
        len = sizeof(clientaddr);
        connectionsocket = accept(socketfd, (struct sockaddr *)&clientaddr, &len);
        if (connectionsocket < 0) {
            if (errno == EINTR)
                printf("Interrupted system call??");
            continue;
        }
 
        printf("Connection from %s\n", inet_ntop(AF_INET, &clientaddr.sin_addr, buffer, sizeof(buffer)));
 
        // Create a new thread to handle the client
        pthread_t thread_id;
        int *client_sock = malloc(sizeof(int));
        *client_sock = connectionsocket;
        pthread_create(&thread_id, NULL, handle_client, client_sock);
    }
 
    close(socketfd);
    return 0;
}
 
void* handle_client(void* arg) {
    int connectionsocket = *(int*)arg;
    char databuf[1024];
    readstring(connectionsocket, databuf); // Read the string
    printf("Finished serving one client\n");
    close(connectionsocket);
    free(arg);
    pthread_exit(NULL);
}
 
void readstring(int connectionsocket, char *fname) {
    int pointer = 0, n;
    while ((n = read(connectionsocket, (fname + pointer), 1024)) > 0) {
        pointer = pointer + n;
    }
    fname[pointer] = '\0';
    printf("Server: Received %s\n", fname);
}

