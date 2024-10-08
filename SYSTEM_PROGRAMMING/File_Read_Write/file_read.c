/*
This program demonstrates how to open a file, read its contents, and then close the file.
*/

#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int fd;
	char buffer[1024];

	//open a file for reading
	fd = open("example.txt",O_RDONLY);
	if(fd == -1)
	{
		perror("open");
		exit("EXIT_FAILURE");
	}

	//Read from the file
	ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
	if(bytesRead == -1)
	{
		perror("read");
		close(fd);
		exit("EXIT_FAILURE");
	}

	//output what has been read
	printf("Read %zd bytes : %s\n",bytesRead,buffer);

	//close the file
	close(fd);
	return 0;
}
