#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#define MAXSTUD 10

void writeData(Student *student, int numStudents);
void readData(const char *file, Student *student, int *numStudents);
float calculateGPA(float grades[], int numGrades);
void mergeSort(Student arr[], int left, int right, int type);
void searchForStudent(Student students[], int numStudents);
Student *searchID(Student arr[], int Id, int numStudents);
Student *searchName(Student arr[], char *name, int numStudents);

int main() {
   //testing GPA
   float invalidGrades[] = {88.0, 101.0, 77.0};
   int size1 = sizeof(invalidGrades)/sizeof(invalidGrades[0]);
   float validGrades[] = {75.0, 54.0, 67.0, 42.0};
   int size2 = sizeof(validGrades)/sizeof(validGrades[0]);
   printf("Invalid Test: \n");
   printf("%.1f\n", calculateGPA(invalidGrades, size1));
  
   printf("\n");
   printf("Valid Test: \n");
   printf("%.1f\n", calculateGPA(validGrades, size2));
   
   printf("_______________________________\n");
   
   //Empty file reading 
   Student stud[MAXSTUD];
   int numStudents = 0;
   printf("Empty file test: \n");
   readData("empty.csv", stud, &numStudents);
   
   printf("_______________________________\n");

   //Valid data test
   printf("Valid file test: \n");
   readData("student.csv", stud, &numStudents);
   int type;
   
   Student student[] = {
   {1, "sierra", "Java", 95.0, "Chemistry", 67.0, "Calculus", 55.0},
   {2, "juanita", "Math", 99.0, "Science", 100.0, "English", 44.0},
   {4, Another, Math, 80.0, Science, 75.0} } 
   
   printf("\n --How do you want to sort the students:\n 1.) ID\n 2.) GPA\n 3.) Name\n ");
            printf("Choice of sort: ");
            scanf("%d", &type);
            printf(mergeSort(student, 0, numStudents-1, type));
   
   
   
   
   
   
   
   


}
