#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 5 // didn't need to make changes but oly here

int main()
{
    char matrix[SIZE][SIZE];
    for (int i = 0; i<SIZE; i++) {
        for (int j = 0; j<SIZE; j++) {
            matrix[i][j] = '0';
        }
    }

    printf("Printing the matrix i) task: \n");
    for (int i = 0; i<SIZE; i++) {
        for (int j = 0; j<SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }


    printf("\ninput a choice of pattern: \n");
    printf("Pattern-1: Left diagonal\n");
    printf("Pattern-2: Right diagonal\n");
    printf("Pattern-3: Borders\n");
    printf("Pattern-4: Center\n");
    printf("input a choice of pattern: ");
    
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        for (int i = 0; i < SIZE; i++) {
            matrix[i][i] = '*';
        }
    }

    else if (choice == 2) {
        for (int i = 0; i < SIZE; i++) {
            matrix[i][SIZE - i - 1] = '*';
        }
    }
    
    else if (choice == 3) {
        for (int i = 0; i < SIZE; i++) {
            matrix[0][i] = '*';
            matrix[SIZE - 1][i] = '*';
            matrix[i][0] = '*';
            matrix[i][SIZE - 1] = '*';
        }
    }

    else if (choice == 4) {
        int mid = SIZE / 2;
        for (int i = 0; i < SIZE; i++) {
            matrix[mid][i] = '*';
            matrix[i][mid] = '*';
        }
    }

    else {
        printf("error! choice between 1-4!!!\n");
        return 1;
    }

    printf("\nprinting the result: \n");
    for (int i = 0; i<SIZE; i++) {
        for (int j = 0; j<SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}