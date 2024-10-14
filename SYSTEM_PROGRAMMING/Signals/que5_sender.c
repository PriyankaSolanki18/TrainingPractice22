/*
5. Write two programs: one that sends a SIGUSR1 signal to another process and one that handles the SIGUSR1 signal. Use the kill function to send the signal and demonstrate communication between the two programs.
*/

/*
This program sends a SIGUSR1 signal to another process specified by its PID.
*/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

int main()
{
	pid_t target_pid;

	printf("Enter the PID of the reveiver process: ");
	scanf("%d",&target_pid);

	//send SIGUSR1 signal to the specified PID
	if(kill(target_pid,SIGUSR1) == -1)
	{
		perror("Failed to send SIGUSR1");
		exit(EXIT_FAILURE);
	}
	printf("Sent SIGUSR1 to process %d.\n",target_pid);
	return 0;
}
