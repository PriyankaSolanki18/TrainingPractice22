/*
1.Write a program where the parent process sends a string message to the child process through a pipe. The child process should read the message and print it to the console.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MAX 100

int main()
{
	int pid; //use for fork()
	int fd[2]; //use for pipe ends
	char buffer[MAX]; 
	
	//create the pipe
	if(pipe(fd) == -1)
	{
		perror("pipe");
		exit(1);
	}
	pid = fork();

	if(pid > 0)
	{
		//parent process
		close(fd[0]); //close the read end
		printf("Enter string : ");
		fgets(buffer,MAX,stdin);
		buffer[strlen(buffer)-1] = '\0';

		write(fd[1],buffer,strlen(buffer)+1);
		close(fd[1]); //close write end after writing
		wait(NULL); //wait for child to finish
	}
	else if(pid == 0)
	{
		close(fd[1]); //close the write end
		read(fd[0],buffer,MAX);
		printf("Received message from parent : %s\n",buffer);
		close(fd[0]);
	}
	else
	{
		perror("fork");
		exit(1);
	}
	return 0;
}
