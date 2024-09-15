#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 30

int main() {
    char word[MAX];
    printf("Enter a word: ");
    scanf("%s", word); // Read the word without spaces

    int len = strlen(word);
    int writeIndex = 0; // Index where we will write characters

    // Process each character
    for (int i = 0; i < len; i++) {
        // Write the character if it's not the same as the previous character
        if (i == 0 || word[i] != word[writeIndex - 1]) {
            word[writeIndex++] = word[i];
        }
    }
    
    // Null-terminate the resulting string
    word[writeIndex] = '\0';
    
    printf("Word after removing adjacent duplicate characters: %s\n", word);
    
    return 0;
}

