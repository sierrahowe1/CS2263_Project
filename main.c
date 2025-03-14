#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#define MAXSTUD 10

void writeData(Student *student, int numStudents);
void readData(const char *file, Student *student, int *numStudents);
float calculateGPA(float grades[], int numGrades);
void mergeSort(Student arr[], int left, int right, int type);

int main() {
    Student stud[MAXSTUD];
    int numStudents = 0;
    int type;
    
    readData("student.csv", stud, &numStudents);

    for(int i = 0; i < numStudents; i++) {
       printf("%d, %s ", stud[i].id, stud[i].name);
       for(int j = 0; j < stud[i].numGrades; j++) {
          printf(", %s, %.1f ", stud[i].classes[j], stud[i].grades[j]);
       }
       printf("\n");
    }
    
    printf("How do you want to sort the students:\n 1.) ID\n 2.) GPA\n 3.) Name\n ");
    scanf("%d", &type);
    
    mergeSort(stud, 0, numStudents-1, type);
    writeData(stud, numStudents);
}
