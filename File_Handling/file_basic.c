/*
The main goal of the program is to copy the contents of a file named "test" to another file called "sample," converting all alphabetic characters to uppercase in the process, and then display the contents of the "sample" file.
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

//functions
int display(FILE *);
int copy_files(FILE *, FILE *);

int main()
{
	FILE *input=NULL, *output=NULL;
	int ret_val=1; //can be used as a flag indicating success for certain operations. Initializing it ensures that it has a known value before being used in the program.

	input=fopen("test","r");
	if(input == NULL)
	{
		printf("Opening 'test' failed\n");
		return EXIT_FAILURE;
	}

	output=fopen("sample","w");
	if(output == NULL)
	{
		printf("Opening 'sample' failed\n");
		return EXIT_FAILURE;
	}

	ret_val = copy_files(input,output);
	if(ret_val == 0)
	{
		printf("Error in copying a file\n");
		return EXIT_FAILURE;
	}
	
	ret_val = fclose(output);
	if(ret_val != 0)
	{
		printf("Error in closing 'sample' file\n");
		return EXIT_FAILURE;
	}

	ret_val = fclose(input);
	if(ret_val != 0)
	{
		printf("Error in closing 'test' file\n");
		return EXIT_FAILURE;
	}

	output = fopen("sample","r");
	if(output == NULL)
	{
		printf("Opening 'sample' falied\n");
		return EXIT_FAILURE;
	}

	ret_val = display(output);
	if(ret_val == 0)
	{
		printf("Displaying 'output' failed\n");
		return 0;
	}

	ret_val = fclose(output);
	if(ret_val != 0)
	{
		printf("Error in closing 'output' file\n");
		return EXIT_FAILURE;
	}
	return 0;
}

//functions definitions

int display(FILE *arg_file)
{
	char file_char = '\0'; //used to store characters read from the file.

	while(1)
	{
	/*feof returns a non-zero value (true) when the end of the file is reached. If it is true, the loop breaks, stopping further reading.*/
	
	/*
	if(feof(arg_file) != 0)
		{
			break;
		}
	*/

		file_char = (char)fgetc(arg_file);
		/*
		The key change is to read a character first and then check if it was successful or if it hit EOF. This prevents any potential issues with printing invalid characters after EOF
		*/
		if(feof(arg_file) || ferror(arg_file)) 
		{
    		break;
		}
		printf("%c", file_char);
	
	/*
fgetc(arg_file) reads the next character from the file and returns it as an int. If it successfully reads a character, it is cast to a char and stored in file_char.
printf("%c", file_char); prints the character to the standard output.
	*/
	}
	printf("\n");
	return 1;
}


int copy_files(FILE *in_file, FILE *out_file)
{
	/*
	re=0; --> This variable will store the return value of fputc, which is used to check if writing to the output file is successful.
	*/
	int ret=0;

	char file_char = '\0', out_char = '\0';

	while(1)
	{
		/*
		if(feof(in_file) != 0)
		{
			break;
		}
		*/

		file_char=(char)fgetc(in_file);
		//check for EOF after reading
		if(feof(in_file))
		{
			break;
		}
		//check for read error
		if(ferror(in_file))
		{
			return 0;
		}
		if(isalpha(file_char))
		{
			out_char = toupper(file_char);
			ret = fputc(out_char,out_file);
			
		/*
		    if(EOF == ret)
			{
				return 0;
			}
		*/
		}
		else
		{
			ret = fputc(file_char, out_file);
			/*
			if(EOF == ret)
			{
				return 0;
			}
			*/
		}
		//check for write error
		if(ret == EOF)
		{
			return 0;
		}

	}
	return 1;
}
