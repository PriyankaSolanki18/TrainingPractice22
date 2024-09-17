#include<stdio.h>


#define PI 3.14

#define SQUARE(x) ((x) * (x))


int main() {
    int i = 2;
	

    printf("%d\n", SQUARE(i++));  
    return 0;
}


