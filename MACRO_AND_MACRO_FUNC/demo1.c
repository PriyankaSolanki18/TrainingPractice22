#include <stdio.h>

#define SUCCESS 0
#define FAILURE -1

int div(int a, int b)
{

	return a/b;
}


int divide(int a, int b, int *result) {
    if (b == 0) {
        return FAILURE; // Error: division by zero
    }
    *result = a / b;
    return SUCCESS; // Success
}

int main() {
    
	int x = 10, y = 0;
    int result;
    
   if (divide(x, y, &result) != SUCCESS) {
        printf("Error: Division by zero\n");
    } else {
        printf("Result: %d\n", result);
    }


    return 0;
}


