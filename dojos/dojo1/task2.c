#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main()
{
    int a = 5;
    int b = 3;
    int c = 9;

    int max = (a > b) 
        ? ((a > c) ? a : c)
        : ((b > c) ? b : c);
    printf("%d\n", max);
}