/***************************************************************************
*	FILENAME : exec.c
*	DESCRIPTION:Contains Code for a program that demonstrates the 
*	use of exec call
*	Invoke the Executable as a.out
*	Copyright 2010 Aricent 
****************************************************************************/

#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int status, retval, childid;
	pid_t pid; /* Return value of fork*/

	printf("Before Fork\n");

	if((pid = fork()) < 0)
	{
		printf("Fork error : %s", strerror(errno));
		exit(1);
	}
	else if(pid == 0) /* child */
	{
		retval = execlp("ls","ls","-l",(char*)0);
		if(retval < 0)
		{
			printf("Exec error : %s",strerror(errno));
			exit(1);
		}
		printf("Cannot come here");
	}
	else /* Parent Executting */
	{
		childid = wait(&status);
		printf("Parent = %d, Child = %d exited with status = %d",getpid(),childid,WEXITSTATUS(status));
	}
	return 0;
}
