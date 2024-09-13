/*4. Define a structure to hold the product sales information, structure will contain the product_ID and total_sales_amount. 
	Write a program that accepts multiple product records (product_ID and total_sales_amount) and prints them in decreasing order of total_sales_amount.
	In case there are multiple records pertaining to the same product_id, the program should choose a single record containing the highest total_sales_amount.
	Program should take multiple line input.
	Each subsequent line of input will contain a Product record, that is, a product_ID and total_sales_amount(separated by a hyphen). 
	The output should consist of the combination of product_ID and corresponding total_sales_amount in decreasing order of score.
Sample Input:
P1001-200
P1002-150
P1003-300
P1001-100
P1002-200
P1003-50
P1001-50
P1002-250
Sample Output:
P1003-300
P1002-250
P1001-200
*/
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 30

typedef struct{
    char product_ID[MAX];
    int total_sales_amount;
}product;

 int main(){
     int n;
     printf("Enter number of products you want to enter : ");
     scanf("%d",&n);
     getchar();
     
     product p[n];
     
     for(int i=0;i<n;i++){
         char line[MAX+10]; // buffer to read input line
         printf("\nEnter prod %d details as ProductID-Amount: ", i+1);
         fgets(line, sizeof(line), stdin);
         //parse product_ID and total_sales_amount from the line
         char *token = strtok(line,"-");
         if(token != NULL){
             strcpy(p[i].product_ID,token);
         }
         token = strtok(NULL,"-");
         if(token != NULL){
             p[i].total_sales_amount = atoi(token);
         }
     }
     
     //Printing without sorting on total_sales_amount
     //printing after sorting
     printf("\nPrinting in decreasing order of total_sales_amount :-\n");
     //int k=0;
     for(int i=0;i<n;i++){
         printf("Book %d : ",i+1);
         printf("%s-%d\n",p[i].product_ID,p[i].total_sales_amount);
         //k++;
     }
     
     //Aggregating records with same product ID
     int unique_cnt = 0; //no. of unique products
     product unique_prod[MAX];
     
     for(int i=0;i<n;i++){
         int index = -1;
         //check if prod id already exist in unique_prod
         for(int j=0;j<unique_cnt;j++){
             if(strcmp(unique_prod[j].product_ID,p[i].product_ID) == 0){
                 index = j;
                 break;
             }
         }
         if(index == -1){
             //prod id not found, add new prod
             strcpy(unique_prod[unique_cnt].product_ID, p[i].product_ID);
        unique_prod[unique_cnt].total_sales_amount = p[i].total_sales_amount;
        unique_cnt++;
         }else{
             // prod id found, update if the new amount is higher
             if (p[i].total_sales_amount > unique_prod[index].total_sales_amount) {
            unique_prod[index].total_sales_amount = p[i].total_sales_amount;
           }
         }
     }
     
     //Printing in decreasing order of total_sales_amount
     //sorting
     for(int i=0;i<unique_cnt-1;i++){
         for(int j=i+1;j<unique_cnt;j++){
             if (unique_prod[i].total_sales_amount < unique_prod[j].total_sales_amount) {
            // Swap total_sales_amount
            int temp_amount = unique_prod[i].total_sales_amount;
            unique_prod[i].total_sales_amount = unique_prod[j].total_sales_amount;
            unique_prod[j].total_sales_amount = temp_amount;

            // Swap product_ID
            char temp_ID[MAX];
            strcpy(temp_ID, unique_prod[i].product_ID);
            strcpy(unique_prod[i].product_ID, unique_prod[j].product_ID);
            strcpy(unique_prod[j].product_ID, temp_ID);
             }
         }
     }
     //printing after sorting
     printf("\nPrinting in decreasing order of total_sales_amount :-\n");
for (int i = 0; i < unique_cnt; i++) {
    printf("Book %d : ", i + 1);
    printf("%s-%d\n", unique_prod[i].product_ID, unique_prod[i].total_sales_amount);
}
     
     return 0;
 }
