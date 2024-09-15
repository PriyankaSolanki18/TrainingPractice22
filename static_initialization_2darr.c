#include<stdio.h>
#include<string.h>
 
int main()
{
    char name[3][4];
    int i;
    printf("Enter 3 names\n");
    for(i = 0; i < 3; i++)
    {
      fgets(name[i],3,stdin);
      if(name[i][strlen(name[i])-1] == '\n')
         name[i][strlen(name[i])-1] ='\0';
    }
    printf("The 3 names\n");
    for(i = 0; i < 3; i++)
        printf("%s\n", name+i);
}
