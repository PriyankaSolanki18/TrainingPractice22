#include <stdio.h>

int main() {
   int n;
   printf("\nEnter size of arr : ");
   scanf("%d",&n);
   int arr[n];
   printf("Enter array elements from 1 to %d : ",n);
   for(int i=0;i<n;i++){
       scanf("%d",&arr[i]);
   }
   
   //sort the arr
   for(int i=0;i<n;i++){
       for(int j=i+1;j<n;j++){
           if(arr[i] > arr[j]){
               int temp = arr[i];
               arr[i] = arr[j];
               arr[j] = temp;
           }
       }
   }
   printf("Sorted array is : ");
   for(int i=0;i<n;i++){
       printf("%d ",arr[i]);
   }
   
   //finding the missing element
   int repeating_val;
   for(int i=0;i<n;i++){
       if(arr[i] == arr[i+1]){
           repeating_val=arr[i];
       }
   }
   printf("\nThe missing element is : %d\n\n",repeating_val+1);
   
   return 0;
}
