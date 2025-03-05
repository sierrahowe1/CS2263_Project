#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 1024
#define MAXLEN 30
#include "student.h"

float calculateGPA(float grades[], int numGrades) {
    float total = 0.0;
    float average = 0;
    if (numGrades == 0) {
        printf("There are no grades associated with this student\n");
        return 0.0;
    }
    
    for (int i = 0; i < numGrades; i++) {
        total += grades[i]; // Sum all grades
    }
    
    average =  total / numGrades; // Calculate and return GPA
    float GPA = (average / 100) * 4.3;
    return GPA;
}

void readData(const char *file, Student *student, int *numStudents) {
    char lines[MAXSIZE];
    
    FILE *input = fopen(file, "r");
    if (input == NULL) {
        perror("Could not open file");
        return;
    }
    
    while (fgets(lines, MAXSIZE, input) != NULL) {
        if (*numStudents >= 100) { // Ensure we don't exceed the array size
            printf("Warning: Maximum number of students reached. Skipping the rest.\n");
            break;
        }
        
        Student *stud = &student[*numStudents];
        char *del = strtok(lines, ","); // Tokenize the line using comma as delimiter
        
        if (del == NULL) {
            printf("Error: Invalid format in input file.\n");
            continue;
        }
        stud->id = atoi(del); // Set the student ID
        
        del = strtok(NULL, ","); // Get the student name
        if (del == NULL) {
            printf("Error: Invalid format in input file.\n");
            continue;
        }
        strncpy(stud->name, del, MAXLEN); // Copy the name into the struct
        stud->name[MAXLEN - 1] = '\0'; // Ensure null-termination
        
        stud->numGrades = 0;
        while ((del = strtok(NULL, ",")) != NULL && stud->numGrades < 10) {
            
            strncpy(stud->classes[stud->numGrades], del, MAXLEN); 
            stud->classes[stud->numGrades][MAXLEN - 1] = '\0';
            
            del = strtok(NULL, ",");
            
            if(del == NULL) {
                printf("Error: No grades for this student\n");
                break;
            }
            stud->grades[stud->numGrades] = atof(del); // Convert grade to float and store it
            stud->numGrades++; // Increment the number of grades
        }
        
        stud->GPA = calculateGPA(stud->grades, stud->numGrades); // Calculate GPA
        (*numStudents)++; // Increment the number of students
    }
    
    fclose(input);
}

void writeData(Student *student, int numStudents) {
    FILE *output = fopen("studentGrades.txt", "w");
    if (output == NULL) {
        perror("Could not open file");
        return;
    }
    
    for (int i = 0; i < numStudents; i++) {
        Student *student1 = &student[i];
        fprintf(output, "%d, %s,", student1->id, student1->name); // Print ID and name
        
        if(student1->numGrades != 0) {
            // If there are grades, print each grade and class
            for (int j = 0; j < student1->numGrades; j++) {
                fprintf(output, "%s, %.1f,", student1->classes[j], student1->grades[j]); // Print class and grade
            }
        }
        
        // Only print GPA, even if no grades are available
        fprintf(output, ", %.1f", student1->GPA);
        fprintf(output, "\n"); // Print a newline after each student
    }
    
    fclose(output);
}














