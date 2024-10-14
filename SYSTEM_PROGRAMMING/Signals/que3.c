/*
3. Write a program that ignores the SIGINT signal. Test the program to ensure that pressing Ctrl+C does not interrupt its execution.(Hint use signal(SIGINT, SIG_IGN) to ignore SIGINT)
*/
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

int main()
{
	//ignore SIGINT signal
	signal(SIGINT,SIG_IGN);
	printf("Program is running. Press Ctrl+C to see that it is ignored.\n");

	//main loop to keep the program running
	while(1)
	{	
		//sleep for a short time to prevent busy waiting
		sleep(1);
	}
	return 0; // this line will never be reached
}
