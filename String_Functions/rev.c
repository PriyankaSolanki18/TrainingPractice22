#include <stdio.h>
#include <string.h>

#define MAX 50
int main() {
    
    char str[MAX] = "Hello, World!";
    char rev[MAX];
    int i,n;
    char temp;
    
    printf("Original String: %s\n", str);
     n = strlen(str);  // Find the length of the string
    
    strncpy(rev,str,n+1);
    

    // Swap characters starting from the ends moving towards the middle
    for (i = 0; i < n / 2; i++) {
        // Swap str[i] with str[n - i - 1]
        temp = rev[i];
        rev[i] = rev[n - i - 1];
        rev[n - i - 1] = temp;
    }
    
    printf("Reversed String: %s\n", rev);
    
    return 0;
}
