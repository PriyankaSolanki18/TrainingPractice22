#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>

#define MAX 20

void report_and_exit(char *msg)
{
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[])
{
	int pid;
	char buffer[MAX];
	char write_buffer[MAX];

	if(argc != 3)
	{
		printf("Wrong usage\n");
		exit(1);
	}

	int fd[2]; //for the read and write ends of pipe

	if(pipe(fd) == -1)
	report_and_exit("pipe");

	if((pid = fork()) <0)
	report_and_exit("fork");

	else if(pid == 0)
	{
		//child process
		close(fd[1]); //close the write end
		read(fd[0],buffer,MAX); //read from pipe
		FILE *fp;
		if((fp = fopen(argv[2],"w")) == NULL)
		report_and_exit("fopen");
		fputs(buffer,fp);
		fclose(fp);
		close(fd[0]); //close read end
	}
	else
	{
		//parent process
		close(fd[0]); //close the read end
		FILE *fp;
		int bytes_read;
		if((fp = fopen(argv[1],"r")) == NULL)
		report_and_exit("fopen");
		if(fgets(write_buffer,MAX,fp) != NULL)
		{
			write_buffer[MAX-1] = '\0';
			write(fd[1],write_buffer,strlen(write_buffer)+1); //write to pipe
		}
		write(fd[1],write_buffer,strlen(write_buffer)+1);
		fclose(fp);
		close(fd[1]);
	}
	return 0;
}
