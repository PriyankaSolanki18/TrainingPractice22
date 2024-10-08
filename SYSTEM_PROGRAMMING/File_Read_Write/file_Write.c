#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int fd;

	//open file for writing
	fd = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if(fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}

	//write to the file
	write(fd,"Hello, World!", 13);

	//close the file
	close(fd);

	return 0;
}
