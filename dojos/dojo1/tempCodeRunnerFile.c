#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main()
{

    printf("%d\n", CHAR_MIN);
    printf("%d\n", CHAR_MAX);
    printf("%d\n", UCHAR_MAX);
    printf("%hd\n", SHRT_MIN);
    printf("%hd\n", SHRT_MAX);
    printf("%hu\n", USHRT_MAX);
    printf("%d\n", INT_MIN);
    printf("%d\n", INT_MAX);
    printf("%u\n", UINT_MAX);
    printf("%ld\n", LONG_MIN);
    printf("%ld\n", LONG_MAX);
    printf("%lu\n", ULONG_MAX);
    printf("The min values of unsigned are always 0.\n");
}