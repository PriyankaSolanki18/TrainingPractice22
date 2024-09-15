//Program : Malloc

#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    
       int *a;
       int n;
       printf("Enter how many elements : ");
       scanf("%d",&n);
       
       a = (int *)malloc(n*sizeof(int));
       
       if(a == NULL){
           printf("Memory allocation failed\n");
           return 1;
       }
       
       printf("Enter %d elements : ",n);
       for(int i=0; i<n; i++)
        scanf("%d",a+i);
        
        printf("The input elements in reverse order : ");
        for(int i=n-1; i>=0; i--)
            printf("%d ",*(a+i));
            
            free(a);
    
    return 0;
}
