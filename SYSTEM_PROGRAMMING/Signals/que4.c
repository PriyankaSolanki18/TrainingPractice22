/*
4. Write a program that uses the alarm function to send a SIGALRM signal to itself after 5 seconds. Write a signal handler for SIGALRM that prints a message when the alarm goes off.
*/
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

//signal handler for SIGALRM
void handle_alarm(int sig)
{
	printf("Alarm went off after 5 sec!\n");
}

int main()
{
	//set up the signal handler for SIGALRM
	signal(SIGALRM,handle_alarm);

	//set an alarm to go off in 5 sec
	alarm(5);

	printf("waiting for the alarm to go off...\n");

	//pause prog until a signal is received
	pause(); //this will wait for any signal to be caught
	return 0;
}
