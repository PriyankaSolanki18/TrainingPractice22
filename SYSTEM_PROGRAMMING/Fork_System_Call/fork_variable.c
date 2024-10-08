/* It demonstrate changes to global variable is local to the process */

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<unistd.h>

int x = 1; //global variable

int main()
{
	pid_t pid, a = 5;
	printf("hello\n");

	pid = fork();
	if(pid == 0)
	{
		printf("\nChild has x = %d, a = %d\n", ++x, ++a);
	}
	else
	{
		wait(NULL);
		printf("\nParent has x = %d, a = %d\n", --x, --a);
	}
	printf("Bye from process %d with x =  %d\n",getpid(),x);
	return 0;
}
