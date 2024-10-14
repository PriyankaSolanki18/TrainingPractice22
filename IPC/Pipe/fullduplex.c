#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

#define BUFFER_SIZE 1024

int main()
{
	int pipefd1[2]; //pipe for process A to process B
	int pipefd2[2]; //pipe for process B to process A
	char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];
	pid_t pid;

	//create the first pipe (Process A to process B)
	if(pipe(pipefd1) == -1)
	{
		perror("pipe1");
		exit(EXIT_FAILURE);
	}	

	//create the second pipe (Process B to process A)
	if(pipe(pipefd2) == -1)
	{
		perror("pipe2");
		exit(EXIT_FAILURE);
	}

	//create a child process (process B)
	pid = fork();
	if(pid == -1)
	{
		perror("Fork");
		exit(EXIT_FAILURE);
	}

	if(pid == 0)
	{
		//child process (process B)
		close(pipefd1[1]); //close write end of pipe1 (Process A to process B)
		close(pipefd2[0]); //close read end of pipe2 (process B to process A)

		//read from pipe1 (process A to process B)
		read(pipefd1[0],buffer1,BUFFER_SIZE);
		printf("Process B received : %s\n",buffer1);

		//write to pipe2 (process B to process A)
		write(pipefd2[1],"Hello from B!",13);

        close(pipefd1[0]); //close read end of pipe1
		close(pipefd2[1]); //close write end of pipe2

		_exit(EXIT_SUCCESS);
	}
	else
	{
		// parent process (process A)
		close(pipefd1[0]); // close read end of pipe1 (process A to process B)
		close(pipefd2[1]); //close write end of pipe2 (Process B to proces A)

		//write to pipe1 (process A to process B)
		write(pipefd1[1],"Hello from A!",13);

		//read from pipe2 (process B to process A)
		read(pipefd2[0],buffer2,BUFFER_SIZE);
		printf("Process A received : %s\n",buffer2);

	    close(pipefd1[1]); //close write end of pipe1
		close(pipefd2[0]); //close read end of pipe2

		wait(NULL); //wait for child process (process B) to complete

		exit(EXIT_SUCCESS);
	}
	return 0;
}
