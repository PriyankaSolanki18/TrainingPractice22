#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *thread_func(void *arg)
{
	pthread_mutex_lock(&lock); //blocking call
	//critical section
	printf("Thread %d has entered the critical section.\n",*(int *)arg);
	//simulate work
	sleep(2);
	printf("Thread %d is leaving the critical section.\n",*(int *)arg);
	pthread_mutex_unlock(&lock);
	return NULL;
}

int main()
{
	pthread_t t1, t2;
	int id1=1, id2=2;

	pthread_create(&t1,NULL,thread_func,&id1);
	pthread_create(&t2,NULL,thread_func,&id2);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	pthread_mutex_destroy(&lock);
	return 0;
}
