#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define CORRECT_KEY 3498
#define MAX_ATTEMPTS 5

int main()
{
    int input = 0;
    int max_attempts = MAX_ATTEMPTS;

    while (max_attempts > 0) {
        printf("Enter the code to the lock: ");

        if (scanf("%d", &input) !=1) {
            printf("Please enter a number!\n");
            while (getchar() != '\n');
            max_attempts--;
            continue;
        }
        while (getchar() != '\n');

        if (input == CORRECT_KEY) {
            printf("Access granted!!!\n");
            return 0;
        }   else {
            max_attempts--;
            if (max_attempts > 0) {
                printf("Wrong code!, %d attempts remaining\n", max_attempts);
            }   else {
                printf("Access denied\n");
            }
        }
    }
}

// // What is the most efficient way to make these changes to your code, such that it is easier to make
// more changes in the future? Define values #define CORRECT_KEY 3498
// #define MAX_ATTEMPTS 5