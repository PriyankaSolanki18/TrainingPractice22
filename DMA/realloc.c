//Program : Malloc
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 50

int main() {
    
    int *a = NULL;
    a = (int *)malloc(5*sizeof(int));
    for(int i=0; i<5; i++)
        a[i] = i+1;
    a=(int *)realloc(a,3*sizeof(int));
    for(int i=0;i<5;i++)
        printf("%d ",a[i]);
      
    return 0;
}

