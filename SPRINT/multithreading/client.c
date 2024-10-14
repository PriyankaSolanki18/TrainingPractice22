#include    <stdio.h>
#include    <stdlib.h>
#include    <unistd.h>
#include    <errno.h>
#include    <string.h>
#include    <sys/types.h>
#include    <sys/socket.h>
#include    <netinet/in.h>
#include    <arpa/inet.h>
 
void sendstring(int, char *);
 
int main(int C, char *Arg[]) {
    int fd;
    struct sockaddr_in serveraddress;
 
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        perror("socket");
        exit(1);
    }
 
    if (Arg[1] == NULL) {
        printf("Please give the server's IP Address\n");
        exit(0);
    }
    if (Arg[2] == NULL) {
        printf("Please give the server's Port No\n");
        exit(0);
    }
    if (Arg[3] == NULL) {
        printf("Please give the string to be sent to the server\n");
        exit(0);
    }
 
    memset(&serveraddress, 0, sizeof(serveraddress));
    serveraddress.sin_family = AF_INET;
    serveraddress.sin_port = htons(atoi(Arg[2]));  // Port number
    serveraddress.sin_addr.s_addr = inet_addr(Arg[1]);  // IP address
 
    if (connect(fd, (struct sockaddr *)&serveraddress, sizeof(serveraddress)) < 0) {
        printf("Cannot connect to server");
        exit(1);
    }
 
    sendstring(fd, Arg[3]);
    return 0;
}
 
void sendstring(int fd, char *fname) {
    int n, bytes = 0, written;
    char buffer[1024];
    strcpy(buffer, fname);
    n = strlen(buffer);
    while (bytes < n) {
        written = write(fd, buffer + bytes, (n - bytes));
        bytes += written;
    }
    printf("String: %s sent to server\n", buffer);
}

