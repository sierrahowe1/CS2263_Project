#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#define MAXSTUD 10

void writeData(Student *student, int numStudents);
void readData(const char *file, Student *student, int *numStudents);
float calculateGPA(float grades[], int numGrades);

int main() {
    Student stud[MAXSTUD];
    int numStudents = 0;
    int type;
    
    readData("student.csv", stud, &numStudents);
    
    stud[0].grades[stud->numGrades+1] = 50.0;
    
    for(int i = 0; i < numStudents; i++) {
       printf("%d, %s, ", stud[i].id, stud[i].name);
       
       
       
       for(int j = 0; j < stud->numGrades; j++) {
          printf("%s, %.1f,", stud[i].classes[j], stud[i].grades[j]);
       }
       printf("\n");
       
    }
    
    printf("How do you want to sort: 1.)ID 2.)GPA .3)Name ");
    scanf("%d", &type);
    
    mergeSort()
    
    
    
    writeData(stud, numStudents);
}
