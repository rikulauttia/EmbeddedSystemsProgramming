#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 10

int main()
{
    int sum = 0;
    int i = 1;

    while (i <= N) {
        sum += i;
        printf("%d\n", sum);
        i += 1;
    }

    printf("Final sum %d\n", sum);
}