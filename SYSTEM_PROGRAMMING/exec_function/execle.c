#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>

int main()
{
	//define the environment variable array
	char *env[] = {"PATH=/usr/bin:/bin",NULL};

	printf("Before execle\n");

	//using execle to run /bin/ls with the argument -1 and specified environemnt
	execle("/bin/ls", "ls", "-l", (char *)0, env);

	//if execle fails, the following line will be executed
	fprintf(stderr, "oexecle failed : %s\n", strerror(errno));
	return 1;
}
