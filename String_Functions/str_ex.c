#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, est test";
    char *ptr = strstr(str, "test");
    if (ptr != NULL)
        printf("Found 'W' at position: %ld\n", ptr - str);  // Output: 7
    else
        printf("'W' not found\n");
    return 0;
}
