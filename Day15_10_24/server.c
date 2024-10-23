#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
 
#define PORT 15608
#define MAX_CLIENTS 10
#define CREDENTIALS_FILE "user_credentials.txt"
 
pthread_mutex_t file_mutex;
pthread_mutex_t client_mutex;
 
int client_sockets[MAX_CLIENTS];
int client_count = 0;
 
void *process_request(void *arg);
void *broadcast_message(void *arg);
void readstring(int sock, char *buffer, int size);
int login(const char *username, const char *password);
int signup(const char *username, const char *password);
void add_client(int sock);
void remove_client(int sock);
 
int main() {
    int server_socket, connectionsocket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
 
    pthread_mutex_init(&file_mutex, NULL);
    pthread_mutex_init(&client_mutex, NULL);
 
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
 
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces
    server_addr.sin_port = htons(PORT);
 
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
 
    if (listen(server_socket, MAX_CLIENTS) == 0) {
        printf("Server is listening on port %d\n", PORT);
    } else {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
 
    while (1) {
        addr_size = sizeof(client_addr);
        connectionsocket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_size);
        if (connectionsocket < 0) {
            perror("Connection failed");
            continue;
        }
 
        pthread_t tid;
        if (pthread_create(&tid, NULL, process_request, (void*)(intptr_t)connectionsocket) != 0) {
            perror("Failed to create thread");
        }
        pthread_detach(tid); // Detach the thread to free resources when done
    }
 
    close(server_socket);
    pthread_mutex_destroy(&file_mutex);
    pthread_mutex_destroy(&client_mutex);
    return 0;
}
 
void *process_request(void *arg) {
    int connectionsocket = (int)(intptr_t)arg;
    char option[10];
    char username[100], password[100];
    char message[1024];
 
    // Read the option (login or signup)
    readstring(connectionsocket, option, sizeof(option));
    printf("Server: Received option = %s\n", option);  // Debug print
 
    if (strcmp(option, "signup") == 0) {
        readstring(connectionsocket, username, sizeof(username));
        readstring(connectionsocket, password, sizeof(password));
        printf("Server: Signup requested. Username = %s, Password = %s\n", username, password);  // Debug print
 
        pthread_mutex_lock(&file_mutex); // Lock for thread safety
        if (signup(username, password)) {
            strcpy(message, "Signup successful\n");
        } else {
            strcpy(message, "Signup failed: User already exists\n");
        }
        pthread_mutex_unlock(&file_mutex);
        write(connectionsocket, message, strlen(message));  // Send response back to client
    } else if (strcmp(option, "login") == 0) {
        readstring(connectionsocket, username, sizeof(username));
        readstring(connectionsocket, password, sizeof(password));
        printf("Server: Login requested. Username = %s, Password = %s\n", username, password);  // Debug print
 
        pthread_mutex_lock(&file_mutex); // Lock for thread safety
        if (login(username, password)) {
            strcpy(message, "Login successful\n");
            write(connectionsocket, message, strlen(message)); // Send response to client
 
            // Add client to the list and start broadcasting chat messages
            add_client(connectionsocket);
            broadcast_message((void*)(intptr_t)connectionsocket);
        } else {
            strcpy(message, "Login failed: Invalid credentials\n");
            write(connectionsocket, message, strlen(message)); // Send response to client
        }
        pthread_mutex_unlock(&file_mutex);
    } else {
        strcpy(message, "Invalid option\n");
        write(connectionsocket, message, strlen(message)); // Send response to client
    }
 
    close(connectionsocket);
    return NULL;
}
 
void *broadcast_message(void *arg) {
    int connectionsocket = (int)(intptr_t)arg;
    char message[1024];
    int n;
 
    while (1) {
        n = read(connectionsocket, message, sizeof(message) - 1);
        if (n <= 0) {
            // Client disconnected
            remove_client(connectionsocket);
            close(connectionsocket);
            return NULL;
        }
 
        message[n] = '\0'; // Null-terminate the message
        printf("Broadcasting message: %s\n", message); // Debug print
 
        pthread_mutex_lock(&client_mutex); // Lock for thread safety
        for (int i = 0; i < client_count; i++) {
            if (client_sockets[i] != connectionsocket) {
                write(client_sockets[i], message, n); // Send message to all clients except the sender
            }
        }
        pthread_mutex_unlock(&client_mutex); // Unlock mutex
    }
}
 
void readstring(int sock, char *buffer, int size) {
    int n = read(sock, buffer, size - 1);
    if (n < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';  // Null-terminate the string
}
 
int login(const char *username, const char *password) {
    FILE *file = fopen(CREDENTIALS_FILE, "r");
    if (!file) {
        perror("Failed to open credentials file");
        return 0;
    }
 
    char stored_username[100], stored_password[100];
    while (fscanf(file, "%s %s", stored_username, stored_password) != EOF) {
        if (strcmp(username, stored_username) == 0 && strcmp(password, stored_password) == 0) {
            fclose(file);
            return 1; // Login successful
        }
    }
 
    fclose(file);
    return 0; // Login failed
}
 
int signup(const char *username, const char *password) {
    FILE *file = fopen(CREDENTIALS_FILE, "a+");
    if (!file) {
        perror("Failed to open credentials file");
        return 0;
    }
 
    char stored_username[100];
    while (fscanf(file, "%s", stored_username) != EOF) {
        if (strcmp(username, stored_username) == 0) {
            fclose(file);
            return 0; // User already exists
        }
    }
 
    fprintf(file, "%s %s\n", username, password); // Save new user
    fclose(file);
    return 1; // Signup successful
}
 
void add_client(int sock) {
    pthread_mutex_lock(&client_mutex);
    if (client_count < MAX_CLIENTS) {
        client_sockets[client_count++] = sock;
    }
    pthread_mutex_unlock(&client_mutex);
}
 
void remove_client(int sock) {
    pthread_mutex_lock(&client_mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == sock) {
            client_sockets[i] = client_sockets[--client_count]; // Remove client
            break;
        }
    }
    pthread_mutex_unlock(&client_mutex);
}
