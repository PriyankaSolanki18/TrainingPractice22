/*
2.Create a parent and child process that communicate bidirectionally using two pipes. The parent sends a message to the child, and the child sends a modified version of the message back to the parent.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MAX 100

void to_upper(char *str)
{
	for(int i=0;str[i];i++)
	{
		str[i] = toupper((unsigned char)str[i]);
	}
}

int main()
{
	int fd1[2], fd2[2];
	char buffer[MAX];

	if(pipe(fd1) == -1 || pipe(fd2) ==-1)
	{
		perror("pipe");
		exit(1);
	}

	int pid = fork();

	if(pid > 0)
	{
		//parent process
		close(fd1[0]); //close read end of pipe1
		close(fd2[1]); //close write end of pipe2

		printf("Enter a message: ");
		fgets(buffer,MAX,stdin);
		buffer[strlen(buffer)-1] ='\0';

		//send message to child
		write(fd1[1],buffer,strlen(buffer)+1);
		close(fd1[1]); //close write end after sending

		//wait for the child to send a message back
		read(fd2[0],buffer,MAX);
		printf("Received from child: %s\n",buffer);

		close(fd2[0]); //close read end after reading
		wait(NULL); //wait for child to finish
	}
	else if(pid == 0)
	{
		//child process
		close(fd1[1]); //close write end of pipe1
		close(fd2[0]); //close read end of pipe2

		//read message from parent
		read(fd1[0],buffer,MAX);
		printf("Received from parent: %s\n",buffer);

		//convert message to uppercae
		to_upper(buffer);

		//send modified message back to parent
		write(fd2[1],buffer,strlen(buffer)+1);
		close(fd2[1]); // close write end after sending

		close(fd1[0]); //close read end after reading
	}else{
		perror("fork");
		exit(1);
	}
	return 0;
}
