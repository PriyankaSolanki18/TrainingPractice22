// use of wait() func

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t pid = fork(); //create a new process

	if(pid < 0)
	{
		//fork failed
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	if(pid == 0)
	{
		// child process
		printf("child process running...\n");
		sleep(2);
		exit(42);
	}else{
		//parent process
		int status;
		pid_t child_pid = wait(&status); //wait for the child to finish

		if(child_pid > 0){
			printf("child process with PID %d terminated\n",child_pid);
			if(WIFEXITED(status)){
				printf("Child exited wth status %d\n",WEXITSTATUS(status));
			}
		}
	}

	return 0;
}
