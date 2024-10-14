/*
1. Write a program that catches the SIGINT signal (triggered by Ctrl+C) and prints a custom message. Ensure that the program does not terminate when SIGINT is received but continues running.
*/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

//signal handler function
void handle_sigint(int sig)
{
	printf("Caught SIGINT! Press Ctrl+C again to exit.\n");
}

int main()
{
	//set up the signal handler
	if(signal(SIGINT,handle_sigint) == SIG_ERR)
	{
		perror("Failed to set up signa handler");
		exit(EXIT_FAILURE);
	}
	printf("Program is running. Press Ctrl+C to trigger SIGINT.\n");

	//main loop to keep the program running
	while(1)
	{
		//sleep for a short time to prevent busy waiting
		sleep(1);
	}
	return 0;
}
