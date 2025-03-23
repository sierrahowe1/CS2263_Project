#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#define MAXSTUD 10

void writeData(StudentNode** head, int numStudents);
void readData(const char *file, StudentNode** head, int *numStudents);
float calculateGPA(float grades[], int numGrades);
void mergeSort(StudentNode** head, int type);
void searchForStudent(StudentNode **head, int numStudents);
Student *searchID(StudentNode **head, int Id);
Student *searchName(StudentNode **head, char *name);
void addStudent(StudentNode** head, Student newStudent);
void freeList(StudentNode** head);
void removeStudent(StudentNode **head, int id);
void printBarChart(Student *student);

int main() {
   printf("_______________________________\n");
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
   StudentNode* head = NULL;
   int numStudents = 0;
   printf("Empty file test: \n");
   readData("empty.csv", &head, &numStudents);
   
   printf("_______________________________\n");

   //Valid data test
   printf("Valid file test: \n");
   readData("student.csv", &head, &numStudents);
   
   
   printf("_______________________________\n");  
   
   
   int type;
   
   
   StudentNode b ={{4, "Another", {80.0, 75.0}, {"Math","Science"}, 2, 3.3 }, NULL}; 
   StudentNode a ={{2, "juanita", {99.0, 100.0, 44.0}, {"Math","Science","English"}, 3, 3.5}, &b};
   StudentNode start = {{1, "sierra", {95.0, 67.0, 55.0}, {"Java","Chemistry","Calculus"}, 3, 3.1}, &a};
   
   Student try = {1, "sierra", {95.0, 67.0, 55.0}, {"Java","Chemistry","Calculus"}, 3, 3.1};
   Student *pointer = &try;
   StudentNode* list = &start;
   printBarChart(pointer);
  
   printf("\n --How do you want to sort the students:\n 1.) ID\n 2.) GPA\n 3.) Name\n ");
            printf("Choice of sort: ");
            scanf("%d", &type);
            mergeSort(&list, type);
            StudentNode* current = &start;
            while( current != NULL) {
            	printf("%d, %s, %.1f", current->data.id, current->data.name, current->data.GPA);
                for (int j = 0; j < current->data.numGrades; j++) {
                   printf(", %s, %.1f", current->data.classes[j], current->data.grades[j]);
                } 
                printf("\n");
                current = current->next;
            }
}
