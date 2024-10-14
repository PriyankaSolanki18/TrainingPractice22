/*
This program waits for a SIGUSR1 signal and handles it by printing a message.
*/
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

//signal handler for SIGUSR1
void handle_sigusr1(int sig)
{
	printf("Received SIGUSR1 signal!\n");
}

int main()
{
	//set up signal handler for SIGUSR1
	signal(SIGUSR1,handle_sigusr1);

	printf("Receiver is runnig. PID: %d\n",getpid());
	printf("Waiting for the SIGUSR1 signal...\n");

	//loop to keep the receiver running
	while(1)
	{
		pause(); //wait for a signal
	}
	return 0;
}
