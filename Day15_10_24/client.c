#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
 
#define SERVER_IP "127.0.0.1" // Change this to the server's IP address
#define PORT 15608
 
void sendstring(int sock, const char *str);
void login_or_signup(int sock);
void *receive_messages(void *arg);
 
int main() {
    int sock;
    struct sockaddr_in server_addr;
 
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
 
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);
 
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        exit(EXIT_FAILURE);
    }
 
    // Start a thread to receive messages
    pthread_t recv_thread;
    if (pthread_create(&recv_thread, NULL, receive_messages, (void*)(intptr_t)sock) != 0) {
        perror("Failed to create thread for receiving messages");
        exit(EXIT_FAILURE);
    }
 
    // Detach the thread so it can run independently
    pthread_detach(recv_thread);
 
    // Login or Signup
    login_or_signup(sock);
 
    // After successful login, enter the chat loop
    char message[1024];
    while (1) {
        printf("You: ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = '\0'; // Remove newline
 
        if (strlen(message) == 0) {
            continue; // Skip if the user didn't type anything
        }
 
        sendstring(sock, message); // Send message to the server
    }
 
    close(sock);
    return 0;
}
 
void sendstring(int sock, const char *str) {
    write(sock, str, strlen(str));
}
 
void login_or_signup(int sock) {
    char option[10], username[100], password[100], response[1024];
 
    printf("Enter 'login' or 'signup': ");
    fgets(option, sizeof(option), stdin);
    option[strcspn(option, "\n")] = '\0'; // Remove newline
 
    sendstring(sock, option);
 
    if (strcmp(option, "login") == 0 || strcmp(option, "signup") == 0) {
        printf("Username: ");
        fgets(username, sizeof(username), stdin);
        username[strcspn(username, "\n")] = '\0'; // Remove newline
        sendstring(sock, username);
 
        printf("Password: ");
        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = '\0'; // Remove newline
        sendstring(sock, password);
 
        read(sock, response, sizeof(response) - 1); // Read server response
        response[strlen(response)] = '\0'; // Null-terminate the response
        printf("%s", response);
    } else {
        printf("Invalid option\n");
        exit(0);
    }
}
 
void *receive_messages(void *arg) {
    int sock = (int)(intptr_t)arg;
    char message[1024];
    int n;
 
    while (1) {
        n = read(sock, message, sizeof(message) - 1);
        if (n <= 0) {
            printf("Disconnected from server\n");
            exit(0);
        }
 
        message[n] = '\0'; // Null-terminate the message
        printf("Server: %s\n", message);
    }
 
    return NULL;
}
