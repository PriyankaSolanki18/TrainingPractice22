#include <stdio.h>

int main() {
    printf("This file is: %s\n", __FILE__);
    printf("This is line: %d\n", __LINE__);
    printf("Compiled on: %s at %s\n", __DATE__, __TIME__);
    printf("In function: %s\n", __FUNCTION__);

    return 0;
}

