#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int PrintArraySum(int* arr, int size) {
    int sum = 0;
    printf("Printing array: \n");
    for (int i=0; i<size; i++) {
        printf("%d ", *(arr+i));
        sum += *(arr+i);
    }
    printf("\n");
    return sum;
}


int main() {
    int myarray[5] = {10, 20, 30, 40, 50};
    int array_sum = PrintArraySum(myarray, 5);
    printf("total array all elements sum is: %d\n", array_sum);
    return 0;
}