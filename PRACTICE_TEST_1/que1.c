#include <stdio.h>

int main() {
   int n1, n2;
   printf("Enter size of arr 1 : ");
   scanf("%d",&n1);
   printf("Enter size of arr 2 : ");
   scanf("%d",&n2);
   
   int arr1[n1], arr2[n2];
   
   printf("Enter elements of arr 1 : ");
   for(int i=0;i<n1;i++){
       scanf("%d",&arr1[i]);
   }
   printf("Enter elements of arr 2 : ");
   for(int j=0;j<n2;j++){
       scanf("%d",&arr2[j]);
   }
   
   //merge
   int merge_arr[n1+n2];
   int i,j;
   for(i=0;i<n1;i++){
       merge_arr[i]=arr1[i];
   }
   for(int j=0;j<n2;j++){
       merge_arr[i+j]=arr2[j];
   }
   
   printf("Merged array is : ");
   for(int i=0; i<n1+n2; i++){
       printf("%d ",merge_arr[i]);
   }
   
   //remove even no
   //first count odd numbers from merge_arr to calc. size of new arr
   int n3=n1+n2;
   int count=0;
   for(int i=0; i<n3; i++){
       if(merge_arr[i]%2 != 0){
           count++;
       }
   }
   printf("\nSize of arr3 is : %d", count);
   
   //create arr3 for storing only odd numbers
   int arr3[count];
   int k=0;
   for(int i=0; i<n3; i++){
       if(merge_arr[i]%2 != 0){
           arr3[k] = merge_arr[i];
           k++;
       }
   }
   printf("\nArray after removing even numbers : ");
   for(int i=0;i<count;i++){
       printf("%d ",arr3[i]);
   }
   
   //sorting arr 3
   for(int i=0;i<count;i++){
       for(int j=i+1;j<count;j++){
           if(arr3[i] > arr3[j]){
               int temp = arr3[i];
               arr3[i]=arr3[j];
               arr3[j]=temp;
           }
       }
   }
   printf("\nSorted array is : ");
   for(int i=0;i<count;i++){
       printf("%d ",arr3[i]);
   }
   
   return 0;
}
