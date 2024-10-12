#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *thread_function(void *arg)
{
	printf("Detached thread running\n");
	sleep(3);
	printf("detached thread finished\n");
	return NULL;
}

int main()
{
	pthread_t thread;
	pthread_attr_t attr;

	//Initialize thread attribute
	pthread_attr_init(&attr);

	//set the thread to be detached
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	//create a detached thread
	pthread_create(&thread, &attr, thread_function, NULL);
	//destroy the attribute object, as it no longer needed
	pthread_attr_destroy(&attr);
	//main thrread continues
	printf("MAin thread continuing\n");
	sleep(1);
	printf("Main thread finished\n");
	//no need to join the thread

	return 0;
}
