/*
 * week4_3_struct_database.c
 * Author: [Your Name]
 * Student ID: [Your ID]
 * Description:
 *   Simple in-memory "database" using an array of structs.
 *   Students will use malloc to allocate space for multiple Student records,
 *   then input, display, and possibly search the data.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: Define struct Student with fields name, id, grade
struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void) {
    int n;
    struct Student *students = NULL;

    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }

    // TODO: Allocate memory for n Student structs using malloc
    students = malloc(n * sizeof(struct Student));

    // TODO: Read student data in a loop
    for (int i = 0; i < n; i++) {
        printf("Enter name for student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter ID for student %d: ", i + 1);
        scanf("%d", &students[i].id);
        printf("Enter grade for student %d: ", i + 1);
        scanf("%f", &students[i].grade);
    }

    // TODO: Display all student records in formatted output
    printf("\nStudent Records:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", students[i].name, students[i].id, students[i].grade);
    }

    // Optional: Compute average grade or find top student
    float sum = 0;
    int top_index = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].grade;
        if (students[i].grade > students[top_index].grade) {
            top_index = i;
        }
    }
    printf("\nAverage grade: %.2f\n", sum / n);
    printf("Top student: %s with grade %.2f\n", students[top_index].name, students[top_index].grade);

    // TODO: Free allocated memory
    free(students);

    return 0;
}