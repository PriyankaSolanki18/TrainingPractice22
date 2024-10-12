/*
Write a program that uses fork to create a child process. The child process should print "Hello from child!" and the parent process should print "Hello from parent!".
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	pid_t pid = fork();

	if(pid < 0 ){
		perror("fork failed");
		exit(EXIT_FAILURE);
	}else if(pid == 0 ){
		//child
		printf("Hello from child!\n");
	}else{
		//parent
		printf("Hello from parent!\n");
	}
	return 0;
}
