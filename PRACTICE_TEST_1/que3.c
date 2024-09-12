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
   int sum=0;
   printf("Sorted array is : ");
   for(int i=0;i<n;i++){
       printf("%d ",arr[i]);
	   sum += arr[i];
   }

   //finding the missing element
   int repeating_val;
   for(int i=0;i<n;i++){
       if(arr[i] == arr[i+1]){
           repeating_val=arr[i];
       }
   }
  
  int natural_sum=0;
  for(int i=1;i<=n;i++){
  	natural_sum += i;
	}

  int result_sum = sum - repeating_val;

  int missing_ele = natural_sum - result_sum; 
  
   printf("\nThe missing element is : %d\n\n",missing_ele);
   
   return 0;
}
