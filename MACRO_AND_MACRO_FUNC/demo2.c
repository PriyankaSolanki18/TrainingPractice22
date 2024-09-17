#include <stdio.h>
#include <errno.h>
#include <string.h>
#include<stdlib.h>
int main() {
    FILE *file = fopen("non_existent.txt", "r");
    
    if (file == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
		perror("Error");
		exit(EXIT_FAILURE);
    } else {
        fclose(file);
    }
    return 0;
}


