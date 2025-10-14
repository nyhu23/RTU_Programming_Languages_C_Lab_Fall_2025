// week5_task3_student_management_system.c
// Task 3: Mini-project – Student management system with file persistence
// Week 5 – Files & Modular Programming
// TODO: Implement functions to load, save, add, and list students.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define DATA_FILE "students.txt"

typedef struct {
    char name[NAME_LEN];
    int id;
    float gpa;
} Student;

// Function prototypes
int load_students(Student arr[]);
void save_students(Student arr[], int count);
void add_student(Student arr[], int *count);
void list_students(Student arr[], int count);

int main(void) {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    // Load existing data from file using load_students()
    count = load_students(students);

    do {
        printf("\n=== Student Management System ===\n");
        printf("1. List students\n");
        printf("2. Add student\n");
        printf("3. Save and Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                list_students(students, count);
                break;
            case 2:
                add_student(students, &count);
                break;
            case 3:
                save_students(students, count);
                printf("Data saved. See you again. Bye!\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Open DATA_FILE, read records until EOF, return number of records loaded
int load_students(Student arr[]) {
    FILE *fp = fopen(DATA_FILE, "r");
    int count = 0;
    
    if (fp == NULL) {
        printf("Creating a new student database...\n");
        return 0;
    }
    
    while (count < MAX_STUDENTS && 
           fscanf(fp, "%49[^,],%d,%f\n", arr[count].name, &arr[count].id, &arr[count].gpa) == 3) {
        count++;
    }
    
    fclose(fp);
    printf("Ready! Found %d student records.\n", count);
    return count;
}

// Write all students to DATA_FILE
void save_students(Student arr[], int count) {
    FILE *fp = fopen(DATA_FILE, "w");
    
    if (fp == NULL) {
        printf("Oops! Couldn't save the data.\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s,%d,%.2f\n", arr[i].name, arr[i].id, arr[i].gpa);
    }
    
    fclose(fp);
}

// Read input from user and append to array
void add_student(Student arr[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Database is full! Can't add more students.\n");
        return;
    }
    
    printf("What's the student's name? ");
    fgets(arr[*count].name, NAME_LEN, stdin);
    arr[*count].name[strcspn(arr[*count].name, "\n")] = '\0'; // Remove newline
    
    printf("Enter student ID number: ");
    scanf("%d", &arr[*count].id);
    
    printf("Enter GPA: ");
    scanf("%f", &arr[*count].gpa);
    getchar(); // Clear newline
    
    (*count)++;
    printf("Great! Student record added.\n");
}

// Print all students in readable format
void list_students(Student arr[], int count) {
    if (count == 0) {
        printf("No student records found.\n");
        return;
    }
    
    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("Record #%d\n", i + 1);
        printf("  Name: %s\n", arr[i].name);
        printf("  ID: %d\n", arr[i].id);
        printf("  GPA: %.2f\n", arr[i].gpa);
        printf("------------------------\n");
    }
    printf("Total: %d students\n", count);
}