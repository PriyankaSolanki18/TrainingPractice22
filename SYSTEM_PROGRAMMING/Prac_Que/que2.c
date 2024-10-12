/*
Write a program that creates n child processes using fork, where n is provided as a command-line argument. Each child process should print its process ID (PID) and its parent's PID. The parent process should wait for all children to complete before printing "All children have terminated."
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

/*
int main()
{
	int n;
	printf("Enter n:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		if(fork() == 0){
			printf("Child pid : %d from parent pid : %d\n", getpid(),getppid());
			exit(0);
		}
		wait(NULL);
	}
	return 0;
}
*/

//-------------------OR---------------------------

int main(int argc, int *argv[])
{
	if(argc != 2)
	{
		fprintf(stderr, "Usage: %s <no_of_children>\n",argv[0]);
		return 1;
	}
	

int n = atoi(argv[1]);

for(int i=0;i<n;i++)
{
	pid_t pid = fork();
	if(pid < 0)
	{
		perror("fork failed");
		exit(1);
	}
	else if(pid == 0)
	{
		//child
		printf("Child pid : %d from parent pid : %d\n",getpid(),getppid());
		exit(0);
	}
}

// parent process waits for all children to complete 
for(int i=0;i<n;i++)
{
	wait(NULL);
}
printf("All children have terminated.\n");
return 0;
}
