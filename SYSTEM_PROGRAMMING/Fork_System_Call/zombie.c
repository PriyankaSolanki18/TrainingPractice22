#include<stdio.h>
#include<unistd.h>

int main()
{
	pid_t pid = fork();
	if(pid == 0)
	{
		//child process
		printf("Child Process\n");
		_exit(0); //child exits
	}else
	{
		//parent process does not call wait()
		printf("Parent pcess\n");
		sleep(10); //simulate doing some work
	}
	return 0;
}
