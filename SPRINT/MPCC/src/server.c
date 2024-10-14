#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include "functions.h"

int client_sockets[MAX_CLIENTS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    free(arg); // Free the allocated memory for client socket pointer

    // Handle client communication here
    while (1) {
        int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            break; // Connection closed
        }

        // Broadcast received message
        buffer[bytes_received] = '\0';
        printf("Received message: %s\n", buffer); // Log received message
        broadcast_message(buffer, client_socket);
    }

    close(client_socket);
    return NULL;
}

void broadcast_message(const char *message, int sender_id) {
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] != 0 && client_sockets[i] != sender_id) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&mutex);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(5669);

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, 5);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue; // Handle error, try accepting again
        }

        // Store client socket in an array (not shown, you can manage your client sockets)
        int *new_sock = malloc(1); // Allocate memory for the client socket
        *new_sock = client_socket;
        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, (void *)new_sock);
    }

    close(server_socket);
    return 0;
}

