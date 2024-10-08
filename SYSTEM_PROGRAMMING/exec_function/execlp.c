#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>

int main()
{
	printf("Before execlp\n");

	//using execlp to run ls witj the argument -1
	execlp("ls","ls","-l",(char *)0);

	//if execlp fails, the following line will be executed
	fprintf(stderr, "execlp failed: %s\n", strerror(errno));

	return 1;
}
