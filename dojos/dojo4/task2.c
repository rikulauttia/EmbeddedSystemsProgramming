#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int* GetSubArray(int* arr, int N, int* newSize) {
    int min = arr[0];
    int max = arr[0];
    for (int i=1; i<N; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    // counting for memoru allocation
    int count = 0;
    for (int i=0; i<N; i++) {
        if (arr[i] !=min && arr[i] !=max) {
            count++;
        }
    }

    int* subArray = (int*) malloc(count * sizeof(int));
    int j = 0;
    for (int i=0; i<N; i++) {
        if (arr[i] !=min && arr[i] !=max) {
            subArray[j++] = arr[i];
        }
    }
    *newSize = count;
    return subArray;
}

int main() {
    int N;
    printf("input the size of the array: ");
    scanf("%d", &N);

    int* array = (int*) malloc(N * sizeof(int));

    printf("Enter %d integers: \n", N);
    for (int i=0; i<N; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    int newSize = 0;
    int* subArray = GetSubArray(array, N, &newSize);

    if (subArray != NULL && newSize > 0) {
        for (int i=0; i< newSize; i++) {
            printf("%d ", subArray[i]);
        }
        printf("\n");
        free(subArray);

    } else {
        printf("no sub-array to show maybe min or max were the only elements \n");
    }

    free(array);
    return 0;
}