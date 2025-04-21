#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main()
{
    int a = 0;
    int b = 0;
    char operation;

    printf("Input two numbers: ");
    if (scanf("%d %d", &a, &b) !=2) {
        printf("Both inputs need to be integers!!!\n");
        return 1;
    }
    printf("Enter one of the following operations: +, -, *, /, %%\n");
    scanf(" %c", &operation);

    switch(operation)
    {
        case '+':
            printf("result is: %d\n", a+b);
            break;
        
        case '-':
            printf("result is: %d\n", a-b);
            break;

        case '*':
            printf("result is: %d\n", a*b);
            break;

        case '/':
            if (b==0) {
                printf("errorrr!! you cant divide by zero!!\n");
            } else {
                printf("result is: %d\n", a/b);
            }
            break;

        case '%':
            if (b==0) {
                printf("Error moddulus by zero!!\n");
            } else {
                printf("result is: %d\n", a%b);
            }
            break;
        default:
            printf("Error cause invalid operator.\n");
    }
}