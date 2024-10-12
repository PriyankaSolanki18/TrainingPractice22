#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void* arg) {
    printf("Thread is running...\n");
    
    // Set the cancellation type to asynchronous
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

    while (1) {
        printf("Thread is still working...\n");
        sleep(1);  // Simulate ongoing work
    }

    return NULL; // This line may never be reached
}

int main() {
    pthread_t thread;

    // Create the thread
    if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
        perror("Failed to create thread");
        return 1;
    }

    // Sleep for a short time to let the thread run
    sleep(3);

    // Request cancellation of the thread
    printf("Main thread is requesting cancellation...\n");
    pthread_cancel(thread);

    // Wait for the thread to finish
    pthread_join(thread, NULL);
    printf("Main thread is exiting...\n");
    
    return 0;
}

