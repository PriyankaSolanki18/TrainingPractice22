//Program to show the range of datatypes

#include <stdio.h>
#include <limits.h>   // For integer types
#include <float.h>    // For floating-point types

int main() {
    // For char
    printf("char: %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char: 0 to %u\n", UCHAR_MAX);

    // For short
    printf("short: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short: 0 to %u\n", USHRT_MAX);

    // For int
    printf("int: %d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned int: 0 to %u\n", UINT_MAX);

    // For long
    printf("long: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long: 0 to %lu\n", ULONG_MAX);

    // For long long
    printf("long long: %lld to %lld\n", LLONG_MIN, LLONG_MAX);
    printf("unsigned long long: 0 to %llu\n", ULLONG_MAX);

    // For float
    printf("float: %e to %e\n", FLT_MIN, FLT_MAX);

    // For double
    printf("double: %e to %e\n", DBL_MIN, DBL_MAX);

    // For long double
    printf("long double: %Le to %Le\n", LDBL_MIN, LDBL_MAX);

    return 0;
}


