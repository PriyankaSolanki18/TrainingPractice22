#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h" // Include your header file for function declarations

void start_server() {
    // Call the function to start the server
    server_main(); // Assume this function is defined in server.c
}

void start_client() {
    // Call the function to start the client
    client_main(); // Assume this function is defined in client.c
}

int main() {
    int choice;

    while (1) {
        // Display the menu
        printf("Welcome to Multi-Party Conference Chat (MPCC)\n");
        printf("1) Start Server\n");
        printf("2) Start Client\n");
        printf("3) Exit\n");
        printf("Please enter your choice: ");
        
        // Read user input
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                start_server();
                break;
            case 2:
                start_client();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

