/*
2. Modify the previous program to handle both SIGINT and SIGTERM signals. Print a different message for each signal and terminate the program only when SIGTERM is received(use only one sighandler for both SIGINIT and SIGTERM).
*/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

//siganl handler
void handle_signals(int sig)
{
	if(sig == SIGINT)
	{
		printf("Caught SIGINT! Press Ctrl+C again to exit.\n");
	}else if(sig == SIGTERM){
		printf("Caught SIGTERM! Exiting program...\n");
		exit(0);
	}
}

int main()
{
	//set up signal handlers
	signal(SIGINT,handle_signals);
	signal(SIGTERM,handle_signals);

	printf("Program is running. Press Ctrl+C for SIGINT or use 'kill <pid>' for SIGTERM.\n");

	while(1)
	{
		sleep(1); //keep the program running
	}
	return 0;
}
