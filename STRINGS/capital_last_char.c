#include <stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 30
int main() {
    char str[MAX];
    printf("Enter a sentence : ");
    scanf("%[^\n]s",str);
    
    int len = strlen(str);
    for(int i=0;i<len+1;i++){
        if(str[i] == ' ' || str[i] == '\0'){
            str[i-1] = toupper(str[i-1]);
        }
    }
    printf("Output senence is : %s",str);
    return 0;
}
