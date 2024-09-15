//Malloc
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 50

int main() {
    
    int *a = NULL;
    //int *b = NULL;
    
    a = (int *)malloc(5*sizeof(int));
    if(a == NULL){
        printf("Malloc Failed\n");
        return 1;
    }
    
    for(int i=0; i<5; i++)
        a[i] = i+1;
        
    int *temp = (int *)realloc(a,15*sizeof(int));
    if(temp == NULL){
        printf("Realloc Failed");
        return 1;
    }
    a=temp;
    // OR we can also write as :-
    /*
    if(temp != NULL)
    {
        a = temp;
    }
    */
    
    // Note : a = (int *)realloc(a,0*sizeof(int)) is same as deallocate the memory
    // printf("Addr of a : %u",a);
        
    /*a=(int *)realloc(a,3*sizeof(int));
    if(a == NULL){
        printf("Realloc Failed\n");
        return 2;
    }
    */
    
   // b=(int *)malloc(2*sizeof(int));
    
    printf("Addr of a : %u\n",a);        
    //printf("\nAddr of b : %u",b);
    //memset(b,0,2);
    
    for(int i=0;i<20;i++)
        printf("%d ",a[i]);
      
    return 0;
}
