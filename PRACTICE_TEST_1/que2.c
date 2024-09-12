#include <stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 50

int main() {
  int n;
  printf("Enter the number of lines : ");
  scanf("%d",&n);
  getchar();
  
  char lines[n][100];
  // Taking input
    printf("Enter %d lines of input:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Line %d: ", i + 1);
        fgets(lines[i], sizeof(lines[i]), stdin); // read a line of input
        // Remove newline character if present
        int len = strlen(lines[i]);
        if (len > 0 && lines[i][len - 1] == '\n') {
            lines[i][len - 1] = '\0';
        }
    }

    // Printing the input
    // printf("\nThe entered lines are:\n");
    // for (int i = 0; i < n; i++) {
    //     printf("Line %d: %s\n", i + 1, lines[i]);
    // }
    
    //------------------------------------------------
    //input a character
    char ch;
    printf("\nEnter a character : ");
    scanf("%c",&ch);
    getchar();
    
    //input a word
    printf("\nEnter a word : ");
    char word[20];
    fgets(word, sizeof(word), stdin);
    // Remove newline character if present
    int len = strlen(word);
    if (len > 0 && word[len - 1] == '\n') {
        word[len - 1] = '\0';
    }

    //--------------------------------------------------
    
    //Searching character in each line
    for(int i=0;i<n;i++){
        if(strchr(lines[i],ch) != NULL){
            printf("\n%c : found at position %d\n",ch,i+1);
        }else{
            printf("\n%c not found\n");
        }
    }
   
  return 0;
}
