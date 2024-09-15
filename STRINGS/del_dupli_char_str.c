//Remove duplicate char from string
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
 
#define MAX 20
int main()
{
    char* str = NULL;
    str = (char *)malloc(MAX*sizeof(char));
    if(str == NULL){
        printf("Malloc Failed\n");
        return EXIT_FAILURE;
    }
    //memset(str,0,MAX);
    printf("Enter a string : ");
    //int len;
    //fgets(str,MAX,stdin);
    if(fgets(str,MAX,stdin) == NULL)
    {
        // len=strlen(str);
        //     if(str[len-1] == '\n')
        //         str[len-1] = '\0';
        printf("Error in fgets\n");
        free(str);
        return EXIT_FAILURE;
    }
    // else
    // {
    //     printf("Error in fgets\n");
    //     return EXIT_FAILURE;
    // }
    int len=strlen(str);
    if(str[len]>0 && str[len-1]=='\n')
    {
        str[len-1]='\0';
        len--;
    }
    int i,j,k;
    for(i=0;i<len;i++){
        for(j=i+1;j<len;j++){
            if(str[i] == str[j]){
                for(k=j;k<len;k++){
                    str[k] = str[k+1];
                }    
                str[len-1]='\0';
                j--;
                len--;
            }
        }
    }
    printf("String after removing duplicate characters : %s ",str);
    free(str);
    return EXIT_SUCCESS;
}
