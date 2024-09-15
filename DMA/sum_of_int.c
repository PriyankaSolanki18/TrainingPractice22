//Malloc
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 50

int* sum(int , int);

int main() {
    int a=5, b=6;
    int* result=sum(a,b);
    printf("The Sum = %d\n",*result);
    free(result);
    
    return 0;
}
int* sum(int a,int b){
    int* res=(int *)malloc(sizeof(int));
    *res=a+b;
    return res;
}
