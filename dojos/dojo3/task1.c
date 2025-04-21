#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void swap(int* x, int* y) {
    int temporary_safe = *x;
    *x = *y;
    *y = temporary_safe;
}

int main() {
    int a, b;

    printf("enter first number: ");
    scanf("%d", &a);
    printf("enter second number: ");
    scanf("%d", &b);

    printf("printing before swapping: a = %d, b = %d\n", a, b);

    swap(&a, &b);

    printf("printing after swapping: a = %d, b = %d\n", a, b);

    return 0;
}