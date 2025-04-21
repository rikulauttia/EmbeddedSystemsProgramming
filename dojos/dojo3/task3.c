#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void ReverseArray(int* arr, int size) {
    int*start = arr;
    int*end = arr + size - 1;
    
    while(start<end) {
        int util_variable = *start;
        *start = *end;
        *end = util_variable;

        start++;
        end--;
    }
}


int main() {
    int arr[5];
    printf("input array elements: \n");
    for (int i=0; i<5; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    ReverseArray(arr, 5);

    printf("reversed array: \n");
    for (int i=0; i<5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}