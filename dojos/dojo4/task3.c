#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct {
    char name[30];
    int points;
} Student_t;

void PrintStudentDetails(Student_t* studnts, int N) {
    printf("\n student details \n");
    printf("\n");
    for (int i=0; i<N; i++) {
        printf("Student %d:\n", i+1);
        printf("Name: %s\n", studnts[i].name);
        printf("Points: %d\n", studnts[i].points);
        printf("\n");
    }
}

int main() {
    int N;
    printf("input number of students in the class: ");
    scanf("%d", &N);

    // Dynamically allocate memory for the number of students of Student_t type
    Student_t* students = (Student_t*) malloc(N * sizeof(Student_t));

    // Ask the user input details of each student.
    for (int i=0; i<N; i++) {
        printf("\nEnter your name %d: ", i+1);
        scanf("%s", students[i].name);

        printf("Enter your points %s: ", students[i].name);
        scanf("%d", &students[i].points);
    }

    PrintStudentDetails(students, N);

    free(students);
    return 0;
}