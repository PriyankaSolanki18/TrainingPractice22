#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

int main()
{
	printf("Before execl\n");

	//using execl to run /bin/ls with the argument -1
	execl("/bin/ls", "ls", "-l", (char *)0);
	
	//if execl fails, the following line will be executed
	fprintf(stderr,"execl failed : %s\n",strerror(errno));
	return 1;
}
