/*
Create a program that calculates the sum of elements in an array using multiple processes. The array and its size should be passed as command-line arguments. Use fork to split the work among child processes, and each child should compute a portion of the sum. The parent process should then compute the final sum from the results of its children.
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

#define MAX_CHILDREN 10

int main(int argc, int *argv[])
{
	if(argc < 3)
	{
		fprintf(stderr,"Usage : %s <size> <ele1> <ele2> ... <eleN>\n",argv[0]);
		return 1;
	}
	int n=atoi(argv[1]);
	if(n > MAX_CHILDREN)
	{
		fprintf(stderr,"Error: Maximum no. of children is %d\n",MAX_CHILDREN);
		return 1;
	}
	int *arr = malloc(n * sizeof(int));
	for(int i=0;i<n;i++)
	{
		arr[i]=atoi(argv[i+2]);
	}	
	int chunk_size=n/n;
	int rem=n%n;
	int sum[MAX_CHILDREN] = {0};

	for(int i=0;i<n;i++)
	{
		pid_t pid = fork();
		if(pid < 0)
		{
			perror("fork failed");
			free(arr);
			return 1;
		}else if(pid == 0){
			//child process
			int start = i; //each child works on its own index
			sum[i] = arr[start]; //each child calculates its portion
			exit(sum[i]); //exit with the calculated sum
		}
	}
	//parent process collects the result
	for(int i=0;i<n;i++)
	{
	int status;
	wait(&status);
	if(WIFEXITED(status)){
		sum[i] = WEXITSTATUS(status); //get the child's exit status
		}
	}

	//compute final sum
	int total_sum=0;
	for(int i=0;i<n;i++)
	{
		total_sum  += sum[i];
	}
	printf("Total sum : %d\n",total_sum);
	free(arr);
	return 0;
}
