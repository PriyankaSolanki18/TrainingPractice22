#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd;
	fd = open("test.txt",O_WRONLY|O_CREAT, 0777);
	if(fd == -1)
	{
		perror("fopen");
		exit(1);
	}
	dup2(fd,1);
	printf("hello\n");
	write(fd,"hi\n",3);
	fprintf(stdout,"test\n");

	close(fd);

	return 0;
}
