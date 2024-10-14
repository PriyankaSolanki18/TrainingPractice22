#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>

void alr(int sig)
{
	printf("alarm signal is occurring\n");
}
void intr(int sig)
{
	printf("caught interupt\n");
	exit(1);
}
int main()
{
	pid_t pid = fork();

	if(pid == 0)
	{
		signal(SIGALRM,alr);
		alarm(5);
		int i=0;
		while(i<5)
		{
			printf("%d\n",i+1);
			i++;
			sleep(2);
		}
		exit(1);
	}else{
		wait(NULL);
		printf("Parent pid is %d\n",getpid());
		signal(SIGINT,intr);
		while(1)
		{
			printf("Priyanka\n");
			sleep(1);
		}
	}
	return 0;
}
