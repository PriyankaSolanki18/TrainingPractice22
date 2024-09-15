#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10
int main() {
    int n;
    printf("Enter number of lines : ");
    scanf("%d",&n);
    getchar();
    char lines[n][50];
    for(int i=0;i<n;i++){
        printf("Enter line %d : ",i+1);
        fgets(lines[i],sizeof(lines[i]),stdin);
        int len=strlen(lines[i]);
        if(len>0 && lines[i][len - 1] == '\n'){
            lines[i][len - 1] = '\0';
        }
    }
    
    char ch;
    printf("Enter character : ");
    scanf("%c",&ch);
    getchar();
    
    char word[MAX];
    printf("Enter word : ");
    fgets(word,MAX,stdin);
    int len = strlen(word);
    if(word[len-1] == '\n'){
        word[len-1] = '\0';
    }
    
    //-------------------------------------------------------
    int sum_ch=0;
    int pos = -1;
    for(int i=0;i<n;i++){
        for(int j=0;j<50;j++){
            if(lines[i][j] == ch){
                pos = j;
            }
        }
        printf("Position of %c is : %d\n",ch,pos);
        sum_ch += pos;
    }
    printf("Sum of ch positions : %d",sum_ch);
    //-------------------------------------------------------
    
    int sum_word = 0;
    int pos_word;
    for(int i=0;i<n;i++){
        char *first_occur = strstr(lines[i],word);
        if(first_occur != NULL){
            pos_word = first_occur - lines[i];
            sum_word += pos_word;
        }
         printf("\nPosition of %s is : %d",word,pos_word);
    }
   printf("\nSum of word positions is : %d",sum_word);
    
    
    return 0;
}
