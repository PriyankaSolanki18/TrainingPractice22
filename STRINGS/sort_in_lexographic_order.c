//sort an array of strings in lexicographic (dictionary) order:
// Online C compiler to run C program online
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 30
 
void sort(char *arr[], int n);
 
int main() {
    char *arr[]={"Priyanka","Malavika","Arpita","Priyasha","Priyank"};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,n);
    for(int i=0;i<n;i++)
    {
        printf("%s\n",arr[i]);
    }
 
    return  EXIT_SUCCESS;
}
 
void sort(char *arr[], int n)
{
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp(arr[j],arr[i]) < 0){
                char *temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
    return;
}
