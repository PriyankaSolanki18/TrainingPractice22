// 1. Write a program to define a structure called Student with members: name, age, and grade. Create an instance of this structure and take input from the user for each member, then print the values.

#include <stdio.h>
#include<string.h>
#define MAX 30
int main() {
    typedef struct{
        char name[MAX];
        int age;
        char grade;
    }student;
    
    student s1;
    
    printf("Enter the details : \n");
    printf("Enter name : ");
    fgets(s1.name,MAX,stdin);
    // if(s1.name(strlen[s1.name] -1) == '\n'){
    //     s1.name(strlen[s1.name]-1) = '\0';
    // }
    printf("Enter age : ");
    scanf("%d",&s1.age);
    getchar();
    printf("Enter grade : ");
    scanf("%c",&s1.grade);
    getchar();
    
    printf("\nThe entered details : \n");
    printf("Name : %s",s1.name);
    printf("Age : %d\n",s1.age);
    printf("Grade : %c",s1.grade);
    
    return 0;
}
