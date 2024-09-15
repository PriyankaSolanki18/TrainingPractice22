//Program : Malloc
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 50

int main() {
    
       char *str1 = NULL;
       char *str2 = NULL;
       
       str1 = (char *)malloc(MAX*sizeof(char));
       if(str1 == NULL){
           printf("Malloc failed");
           return EXIT_FAILURE;
       }
       memset(str1,0,MAX);
       
       str2 = (char *)malloc(MAX*sizeof(char));
       if(str2 == NULL){
           printf("Malloc failed");
           return EXIT_FAILURE;
       }
       memset(str2,0,MAX);
       
      // str1="PRIYANKA";
      strncpy(str1, "PRIYANKA", MAX - 1);
      printf("My string is : %s\n", str1);
      
       
       strncpy(str1,"Solanki",MAX-1);
      printf("My string is : %s\n",str1);
       
       strncpy(str2,str1,MAX-1);
       printf("My string is : %s\n",str2);
       
       free(str2);
       free(str1);
       
    return 0;
}
