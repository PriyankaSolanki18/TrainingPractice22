#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>

#define FIFO_FILE "MYFIFO"

int main()
{
	int fd;
	char buffer[512];

	mkfifo(FIFO_FILE,0666); //make a fifo

	fd = open(FIFO_FILE,O_WRONLY); //open fifo
	if(fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}

	printf("Enter a message : ");
	fgets(buffer,512,stdin);
	buffer[strlen(buffer)-1] ='\0';
	write(fd,buffer,strlen(buffer)+1); //write
	close(fd); // close

	return 0;
}
