/* 
2. Create a structure Book with members: title, author, and price. Create an array of 5 books and take input from the user for each book's details. Finally, print the details of all books.
*/

#include <stdio.h>
#include<string.h>
#define MAX 30
int main() {
    typedef struct{
        char title[MAX];
        char author[MAX];
        int price;
    }book;
    
    book b[5];
    printf("Enter details of 5 books :- \n\n");
    for(int i=0;i<5;i++){
        printf("Enter details of book %d \n",i+1);
        printf("Enter Book Title : ");
       fgets(b[i].title,MAX,stdin);
       b[i].title[(strcspn(b[i].title,"\n"))] = '\0';
        printf("Enter Author Name : ");
       fgets(b[i].author,MAX,stdin);
       b[i].author[(strcspn(b[i].author,"\n"))] = '\0';
        printf("Enter Book Price : ");
        scanf("%d",&b[i].price);
        getchar();
    }
    
    
    printf("\n\nDetails of Books entered :- \n");
    for(int i=0;i<5;i++){
        printf("Book %d :\n",i+1);
        printf("Book Title : %s",b[i].title);
        printf("\nBook Author : %s",b[i].author);
        printf("\nBook Price : %d\n",b[i].price);
    }
    
    return 0;
}
