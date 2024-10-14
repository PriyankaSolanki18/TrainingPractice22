#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void sig_int_term(int sig)
{
	if(sig == SIGINT)
	{
		printf("interrupt from keyboard\n");
	}
	if(sig == SIGTERM)
	{
		printf("program terminate gracefully\n");
		exit(0);
	}
}

int main()
{
	signal(SIGTERM,sig_int_term);
	signal(SIGINT,sig_int_term);

	while(1)
	{
		printf("hello\n");
		sleep(1);
	}
	return 0;
}
