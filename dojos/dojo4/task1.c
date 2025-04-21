#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int GetSum(int* arr, int N) {
    int sum = 0;
    for (int i=0; i<N; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int N;

    printf("input the size of the array: ");
    scanf("%d", &N);

    int* array = (int*) malloc(N * sizeof(int));

    printf("enter %d integers: \n", N);
    for (int i=0; i<N; i++) {
        printf("element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    int result = GetSum(array, N);

    printf("sum of all elements: %d\n", result);

    free(array);

    return 0;
}