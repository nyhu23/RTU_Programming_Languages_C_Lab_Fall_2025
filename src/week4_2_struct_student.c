/*
 * week4_2_struct_student.c
 * Author: [Your Name]
 * Student ID: [Your ID]
 * Description:
 *   Demonstrates defining and using a struct in C.
 *   Students should define a 'Student' struct with fields like name, id, and grade.
 *   Then create a few instances and print them.
 */

#include <stdio.h>
#include <string.h>

// TODO: Define struct Student with fields: name (char[]), id (int), grade (float)
struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void) {
    // TODO: Declare one or more Student variables
    struct Student student1;

    // TODO: Assign values (either manually or via scanf)
    strcpy(student1.name, "John Doe");
    student1.id = 12345;
    student1.grade = 85.5;

    // TODO: Print struct contents using printf
    printf("Name: %s\n", student1.name);
    printf("ID: %d\n", student1.id);
    printf("Grade: %f\n", student1.grade);

    return 0;
}