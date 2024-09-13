//3. Create a structure Employee with members id, name, and salary. Write a function that takes an employee structure as an argument and prints its members.
#include <stdio.h>
#include<string.h>
#define MAX 30

 typedef struct{
       int id;
       char name[MAX];
       int salary;
    }employee;
    
void fun_struct(employee *e1);

int main() {
    employee e1;

    fun_struct(&e1);
    
    return 0;
}
void fun_struct(employee *e1){
    printf("Enter your employee id : ");
    scanf("%d",&e1->id);
    getchar();
    printf("Enter your name : ");
    fgets(e1->name,MAX,stdin);
    e1->name[strcspn(e1->name,"\n")] = '\0';
    printf("Enter your salary : ");
    scanf("%d",&e1->salary);
    getchar();
    
    printf("\nDetails you entered\n");
    printf("-----------------------\n");
    printf("Employee ID : %d",e1->id);
    printf("\nEmployee Name : %s",e1->name);
    printf("\nEmplyee salary : %d\n",e1->salary);
    
}
