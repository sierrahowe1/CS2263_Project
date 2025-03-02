#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void writeData(Student *student, int numStudents);
void readData(const char *file, Student *student, int *numStudents);
float calculateGPA(float grades[], int numGrades);

int main() {
    Student stud[2];
    int numStudents = 0;
    readData("student.csv", stud, &numStudents);
    writeData(stud, numStudents);
}
