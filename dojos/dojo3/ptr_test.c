#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int main()
{
    int a = 73 ;
    printf("a = %d\n", a);

    int* p = &a; //create an integer pointer, and point it to a
    printf("p (=Addr of a) = %u\n", p); //check the address of a (i.e p)

    printf("a (=value at addr of a) = %d\n", *p); //access a through the pointer p using dereference operator

    int b = *p; //one more example of accessing a using the dereference operator
    //*p => value at address pointed by p (=a)
    printf("b = %d\n", b); //check that now b is same as a

    p++; // increment p i.e point to next address
    printf("After increment, p = %u\n", p);

    int c = *p;
    printf("c = %d\n", c); //check that now b is same as a
    //as of now, next address is not initialized, so a garbage value might be here

    p--; //decrement p i.e point again to a
    printf("After decrement, p = %u\n", p);

    c = *p;
    printf("c = %d\n", c); //check that now b is same as a

    int arr[SIZE] = {1,2,3,4,5}; //create an integer array
    int* pArr = arr; //create a pointer pArr to the array
    printf("pArr (= addr of arr) = %u\n", pArr); //address of array is address of the first element of the array
    printf("array[0] (= value at first addr of arr) = %d\n", *pArr); //access first element of array using pointer
    pArr++; //increment the pointer i.e now point to the next element of the array
    printf("array[1] (= value at second addr of arr) = %d\n", *pArr); //access second element of array using pointer increment

    int i;
    pArr = &arr[0]; //reset the pointer to first element--this is exactly same as line33
    //example for looping through the array
    for(i=0;i<SIZE;i++){
        printf("pArr (= addr of arr[%d]) = %u\n", i, pArr); //address of ith element of array
        printf("array[%d] (= value at first addr of arr) = %d\n", i, *pArr); //access first element of array using pointer
        pArr++; //move to the next array element

    }
    return 0;
}