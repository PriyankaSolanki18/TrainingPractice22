#include<stdio.h>
#include<unistd.h>

int main()
{
	pid_t pid = fork();
	if(pid == 0)
	{
		//child process
		printf("child process: My parent will terminate soon.\n");
		sleep(5); // simulate work
		printf("Child process: My parent is gone, I'm an orphan.\n");
	}else{
		//parent process
		printf("parnt process is terminating.\n");
		_exit(0); //parent exits without waiting
	}
	return 0;
}
