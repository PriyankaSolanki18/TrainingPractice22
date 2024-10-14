#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <pthread.h>

#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024

// Function declarations
void *handle_client(void *arg);
void broadcast_message(const char *message, int sender_id);

#endif // FUNCTIONS_H

