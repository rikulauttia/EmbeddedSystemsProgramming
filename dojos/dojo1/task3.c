#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main()
{
    const int midterm = 40;
    const float final = 90;
    float w1 = 0;
    float total_points = 0;
    int final_grade = 0;

    if (midterm < 0 || midterm > 100 || final < 0 || final > 100) {
        printf("Invalid points\n");
        return 0;
    }

    if (midterm < 50) {
        w1 = 0;
    }

    else if (49 < midterm && midterm < 75) {
        w1 = 0.2;
    }

    else {
        w1 = 0.33;
    }

    total_points = (w1 * midterm + 0.67 * final);

    if (total_points < 50) {
        final_grade = 0;
    }

    else if (49 < total_points && total_points < 60) {
        final_grade = 1;
    }

    else if (59 < total_points && total_points < 70) {
        final_grade = 2;
    }

    else if (69 < total_points && total_points < 80) {
        final_grade = 3;
    }

    else if (79 < total_points && total_points < 90) {
        final_grade = 4;
    }

    else {
        final_grade = 5;
    }

    printf("Final grade is, %d\n", final_grade);
}