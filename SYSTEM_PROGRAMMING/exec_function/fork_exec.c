// Use of fork and exec togethe

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
	pid_t pid = fork(); //create new process

	if(pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	if(pid == 0)
	{
		//child process
		execlp("ls","ls","-l",NULL);  //execute 'ls -l'
		//If exec fails printf error
		perror("execlp failed");
		exit(EXIT_FAILURE);
	}else
	{
		wait(NULL);
		printf("child process finished\n");
	}

	return 0;
}
