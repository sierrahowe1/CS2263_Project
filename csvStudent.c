#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXZISIZE 1024
#define MAXLENGTH 30
#include "student.h"

void readData(const char *file, Student *student, int *numStudents) {
    char lines[MAXSIZE];
    
    FILE *input = fopen(file, "r");
    if (input == NULL) {
        perror("Could not open file");
        return;
    }
    
    while (fgets(lines, MAXSIZE, input) != NULL) {
        Student *stud = &student[*numStudents];
        char *del = strtok(lines, ","); // Tokenize the line using comma as delimiter
        
        stud->id = atoi(del); // Set the student ID
        
        del = strtok(NULL, ","); // Get the student name
        strncpy(stud->name, del, MAXLENGTH); // Copy the name into the struct
        
        stud->numGrades = 0;
        while ((del = strtok(NULL, ",")) != NULL && stud->numGrades < 10) {
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
        fprintf(output, "%d,%s", student1->id, student1->name); // Print ID and name
        
        for (int j = 0; j < student1->numGrades; j++) {
            fprintf(output, ",%.2f", student1->grades[j]); // Print grades
        }
        fprintf(output, "\n"); // Print a newline after each student
    }
    
    fclose(output);
}

float calculateGPA(float grades[], int numGrades) {//calculating GPA
   float total = 0.0;
   float GPA;
   if(numGrades == 0) {
      printf("There are no grades associated with this student");
      return 0.0;
   }
   
   for(int i = 0; i < numGrades; i++) {
      total += grades[i];//adding each grade to the total to create a sum
   }
   
   GPA = total/numGrades;//calculating GPA
   return GPA;
}














