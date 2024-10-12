#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define NUM_THREADS 5 //define the no. of threads to create

//function to be execited by each thread
void *thread_function(void *arg)
{
	int thread_id = *((int *)arg); //retrieve thread ID from an argument
	printf("Hello from thread %d!\n",thread_id);
	pthread_exit(NULL);
}

int main()
{
	pthread_t threads[NUM_THREADS]; //array to hold thread identifiers
	int thread_number[NUM_THREADS]; //array to hold thread number

	//create multiple threads
	for(int i=0;i<NUM_THREADS;i++)
	{
		thread_number[i] = i+1; //set the thread number
		if(pthread_create(&threads[i],NULL,thread_function,(void *)&thread_number[i]) != 0)
		{
			printf("Error creating thread\n");
			return 1;
		}
	}

	//wait for all threads to finish
	for(int i=0;i<NUM_THREADS;i++)
	{
		pthread_join(threads[i],NULL); //join the thread
	}
	printf("All threads have finished execution.\n");
	return 0;
}
