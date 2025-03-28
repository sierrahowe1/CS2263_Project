#include <stdio.h>
#include <stdlib.h>
#include "student.h"

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
   //Testing GPA
	   //Testing invalid grades
	   printf("_______________________________\n");
	   float invalidGrades[] = {88.0, 101.0, 77.0};
	   int size1 = sizeof(invalidGrades)/sizeof(invalidGrades[0]);
	   printf("Invalid GPA Test: \n");
	   printf("%.1f\n", calculateGPA(invalidGrades, size1));
	   
	   //Testing valid grades
	   printf("_______________________________\n");
	   float validGrades[] = {75.0, 54.0, 67.0, 42.0};
	   int size2 = sizeof(validGrades)/sizeof(validGrades[0]);
	   printf("Valid GPA Test: \n");
	   printf("%.1f\n", calculateGPA(validGrades, size2));
    
   //Testing reading data from csv
	   //empty file
	   printf("_______________________________\n");
	   StudentNode* head = NULL;
	   StudentNode* head2 = NULL;
	   int numStudents = 0;
	   int numStudents2 = 0;
	   printf("Empty file test: \n");
	   readData("empty.csv", &head, &numStudents);
	   
	   //Valid data test
	   printf("_______________________________\n");
	   printf("Valid file test: \n");
	   readData("student.csv", &head, &numStudents);
	   
	   printf("_______________________________\n");
	   printf("Invalid file test: \n");
	   readData("invalid.csv", &head2, &numStudents2);
	   
   //Testing barchart
	   printf("_______________________________\n");
	   printf("Printing barchart test: \n");
	   //Student try = {1, "sierra", {95.0, 67.0, 55.0}, {"Java","Chemistry","Calculus"}, 3, 3.1};
	   Student student2;
	   student2.id = 2;
	   student2.name = "Sierra";
	   student2.numGrades = 3;
	   student2.grades = malloc(student2.numGrades * sizeof(float));
	   student2.grades[0] = 95.0;
	   student2.grades[1] = 7.0;
	   student2.grades[2] = 55.5;
	   student2.classes[0] = "Physics";
	   student2.classes[1] = "Math";
	   student2.classes[2] = "English";
	   student2.GPA = 3.1;
	   Student *pointer = &student2;
	   printBarChart(pointer);
   
   //Testing sorting
	   printf("_______________________________\n");  
	   int type;
	   Student student1;
	   student1.id = 1;
	   student1.name = "Juanita";
	   student1.numGrades = 3;
	   student1.grades = malloc(student2.numGrades * sizeof(float));
	   student1.grades[0] = 99.0;
	   student1.grades[1] = 100.0;
	   student1.grades[2] = 44.0;
	   student1.classes[0] = "Math";
	   student1.classes[1] = "Science";
	   student1.classes[2] = "English";
	   student1.GPA = 3.5;
	   
	   Student student3;
	   student3.id = 3;
	   student3.name = "Andy";
	   student3.numGrades = 2;
	   student3.grades = malloc(student2.numGrades * sizeof(float));
	   student3.grades[0] = 80.0;
	   student3.grades[1] = 75.0;
	   student3.classes[0] = "Math";
	   student3.classes[1] = "Science";
	   student3.GPA = 3.3;
	   
	   StudentNode b ={student3, NULL}; 
	   StudentNode a ={student1, &b};
	   StudentNode start = {student2, &a};
	   StudentNode* list = &start;
	  
	   
	   //Testing sort type 1
	   printf("Sorting by ID test: \n");
	   type = 1;
	   mergeSort(&list, type);
	   StudentNode* current = list;
	   while( current != NULL) {
	     printf("%d, %s, %.1f", current->data.id, current->data.name, current->data.GPA);
	     for (int j = 0; j < current->data.numGrades; j++) {
		 printf(", %s, %.1f", current->data.classes[j], current->data.grades[j]);
	     } 
	     printf("\n");
	     current = current->next;
	   }
	   
	   //Testing sort type 2
	   printf("\n");
	   printf("Sorting by GPA test: \n");
	   type = 2;
	   mergeSort(&list, type);
	   current = list;
	   while( current != NULL) {
	     printf("%d, %s, %.1f", current->data.id, current->data.name, current->data.GPA);
	     for (int j = 0; j < current->data.numGrades; j++) {
		 printf(", %s, %.1f", current->data.classes[j], current->data.grades[j]);
	     } 
	     printf("\n");
	     current = current->next;
	   }
	   
	   //Testing sort type 3
	   printf("\n"); 
	   printf("Sorting by name test: \n");
	   type = 3;
	   mergeSort(&list, type);
	   current = list;
	   while( current != NULL) {
	     printf("%d, %s, %.1f", current->data.id, current->data.name, current->data.GPA);
	     for (int j = 0; j < current->data.numGrades; j++) {
		 printf(", %s, %.1f", current->data.classes[j], current->data.grades[j]);
	     } 
	     printf("\n");
	     current = current->next;
	   }
	   
   //Testing search
   	   //Search for students 
   	   //searchForStudent(&list, 3);
   	   
   //Testing remove
   	   //Removing invalid student
   	   int invalidID = 4;
   	   removeStudent(&head, invalidID); 
   	 
	   
	   //Removing valid student
   	   int validID = 3;
   	   removeStudent(&head, validID);   	   	   
}
