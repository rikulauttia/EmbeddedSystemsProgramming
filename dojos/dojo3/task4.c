#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int CountVowels(char* str) {
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            count++;
        }
        i++;
    }
    return count;
}

int main() {
    char input[29];
    printf("input a string (set max string length to 28 and only lowercase alphabets: ");
    scanf("%28s", input);
    int vowels = CountVowels(input);
    printf("number of vowels: %d\n", vowels);
    return 0;
}