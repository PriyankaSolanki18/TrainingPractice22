//Program : Malloc
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 50

int main() {
    
       char *str1 = NULL;
       char *str2 = NULL;
       char *str3 = NULL;
       
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
       
       //Copying of strings -----------------------------
      // str1="PRIYANKA"; 
      strncpy(str1, "PRIYANKA", MAX - 1);
      printf("My string str1 is : %s\n", str1);
      
       
      strncpy(str1,"Solanki",MAX-1);
      printf("My string str1 after copying 'Solanki' to str1 is : %s\n",str1);
       
      strncpy(str2,str1,MAX-1);
      printf("My string str2 after copying str1 to str2 is : %s\n",str2);
      // ----------------------------------------
      
      //Concatenation of strings:-
      str3 = strncat(str1,str2,MAX-1);
      printf("\nAfter concatenation : \n\n");
      
      printf("My string str1 is : %s\n",str1);
      printf("My string str2 is : %s\n",str2);
      printf("my string str3 is : %s\n",str3);
      
      printf("\nAfter copying 'Namaste' to str3 : \n\n");
      strncpy(str3, "Namaste", MAX-1);
      printf("My string str1 is : %s\n",str1); //oz both str1 and str3 are referring to same address"
      printf("My string str2 is : %s\n",str2);
      printf("my string str3 is : %s\n",str3);
      
      // ----------------------------------------
      
      //free(str3); --> Error : as both str1 and str3 have                 same value
      free(str2);
      free(str1);
      
    return 0;
}

