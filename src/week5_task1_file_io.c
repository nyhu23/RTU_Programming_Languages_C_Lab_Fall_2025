// week5_task1_file_io.c
// Task 1: Read and write data from text files
// Week 5 – Files & Modular Programming
// TODO: Fill in the missing parts marked below.

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    char filename[100] = "data.txt";
    char line[256];

    // TODO: 1. Open file for writing (mode = "w")
    fp = fopen(filename, "w");
    
    // TODO: 2. Check if file opened successfully
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }
    
    // TODO: 3. Write 2–3 lines of text to the file using fprintf()
    fprintf(fp, "Hello World! (English)\n");
    fprintf(fp, "¡Hola Mundo! (Spanish)\n");
    fprintf(fp, "Bonjour le monde! (French)\n");
    
    // TODO: 4. Close the file
    fclose(fp);

    // TODO: 5. Open file again for reading (mode = "r")
    fp = fopen(filename, "r");
    
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    
    // TODO: 6. Use fgets() in a loop to read and print each line to the console
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }
    
    // TODO: 7. Close the file
    fclose(fp);

    // BONUS: ask user for filename instead of using default "data.txt"
    printf("Enter filename (or press Enter for 'data.txt'): ");
    fgets(filename, sizeof(filename), stdin);
    
    if (filename[0] == '\n') {
        filename[0] = 'd';
        filename[1] = 'a';
        filename[2] = 't';
        filename[3] = 'a';
        filename[4] = '.';
        filename[5] = 't';
        filename[6] = 'x';
        filename[7] = 't';
        filename[8] = '\0';
    } else {
        
        for (int i = 0; filename[i] != '\0'; i++) {
            if (filename[i] == '\n') {
                filename[i] = '\0';
                break;
            }
        }
    }

    // BONUS: count number of lines read
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    
    int line_count = 0;
    printf("\nReading from %s:\n", filename);
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
        line_count++;
    }
    fclose(fp);
    
    printf("Total lines read: %d\n", line_count);

    return 0;
}