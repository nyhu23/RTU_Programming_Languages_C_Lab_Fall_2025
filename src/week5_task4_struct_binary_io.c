#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    float gpa;
} Student;

void save_student_binary(Student s, const char *filename);
Student load_student_binary(const char *filename);

int main(void) {
    Student s1;
    strcpy(s1.name, "Alice");
    s1.age = 21;
    s1.gpa = 3.75f;

    const char *text_filename = "student.txt";
    const char *binary_filename = "student.bin";

    printf("=== Binary File Operations ===\n");
    save_student_binary(s1, binary_filename);
    Student s2 = load_student_binary(binary_filename);
    
    printf("\nLoaded student data (binary):\n");
    printf("Name: %s\n", s2.name);
    printf("Age: %d\n", s2.age);
    printf("GPA: %.2f\n", s2.gpa);

    printf("\n=== File Size Comparison ===\n");
    FILE *text_file = fopen(text_filename, "r");
    FILE *binary_file = fopen(binary_filename, "rb");
    
    if (text_file != NULL && binary_file != NULL) {
        fseek(text_file, 0, SEEK_END);
        fseek(binary_file, 0, SEEK_END);
        
        long text_size = ftell(text_file);
        long binary_size = ftell(binary_file);
        
        printf("Text file size: %ld bytes\n", text_size);
        printf("Binary file size: %ld bytes\n", binary_size);
        printf("Size difference: %ld bytes\n", text_size - binary_size);
        
        fclose(text_file);
        fclose(binary_file);
    } else {
        printf("Could not open files for size comparison.\n");
    }

    return 0;
}

void save_student_binary(Student s, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening binary file for writing!\n");
        return;
    }
    
    size_t elements_written = fwrite(&s, sizeof(Student), 1, fp);
    if (elements_written == 1) {
        printf("✓ Student record saved to binary file: %s\n", filename);
    } else {
        printf("✗ Error writing to binary file!\n");
    }
    
    fclose(fp);
}

Student load_student_binary(const char *filename) {
    Student s;
    FILE *fp = fopen(filename, "rb");
    
    if (fp == NULL) {
        printf("Error opening binary file for reading!\n");
        strcpy(s.name, "");
        s.age = 0;
        s.gpa = 0.0f;
        return s;
    }
    
    size_t elements_read = fread(&s, sizeof(Student), 1, fp);
    if (elements_read == 1) {
        printf("✓ Student record loaded from binary file: %s\n", filename);
    } else {
        printf("✗ Error reading from binary file!\n");
    }
    
    fclose(fp);
    return s;
}