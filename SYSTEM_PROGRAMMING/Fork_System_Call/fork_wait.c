/*
This program demonstrates basic process management in C. It shows how to create a child process, how to retrieve the child's exit status, and how to manage process synchronization using wait()
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	int pid = 0;
	int retval = 0;
	int status = 8;
	int lcounter = 0;
	
	pid = fork();

	if(pid == 0)
	{
		printf("After exec child process id : %d\n",getpid());
		printf("Child exiting\n");
		exit(status);
	}
	else
	{
		printf("Parent\n");
		retval = wait(&status);
		printf("Retval %d : status %d\n", retval, status);
		printf("Child exit status %d\n", WTERMSIG(status));
		while(lcounter++ < 1)
		{
			sleep(1);
			printf("Parent process id : %d\n",getpid());
		}
	}
	return 0;
}
