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
void printBarChart(Student student);

int main() {
    StudentNode* head = NULL;
    int numStudents = 0;
    int type;
    int choice;
    int id;
    
    printf("\n --!Welcome to S&J Student Grade Management System!--\n");
    printf("\n We offer a variety of services, please check out out menu below \n");
    
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Import student data from CSV\n");
        printf("2. Sort Students by criteria\n");
        printf("3. Export students to a CSV with GPA calculated\n");
        printf("4. Search for a student by name or id\n");
        printf("5. Remove Student\n");
        printf("6. Exit\n");
        printf("\nWhat would you like to do today: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
                readData("student.csv", &head, &numStudents);
                break;
            case 2: 
                printf("\n --How do you want to sort the students:\n 1.) ID\n 2.) GPA\n 3.) Name\n ");
                printf("Choice of sort: ");
                scanf("%d", &type);
                mergeSort(&head, type);
           
                break;

            case 3: 
                writeData(&head, numStudents);
                break;
            case 4:
                printf("Search for student by: \n");
                searchForStudent(&head, numStudents);
                break;
            case 5: 
                printf("Which student would you like to remove (enter their ID): \n");
                printf("ID: ");
                scanf("%d", &id);
                removeStudent(&head, id);
                break;
            case 6:
                freeList(&head);
                printf("\nThank you for using our system! Have a lovely day\n");
                printf("\n");
                return 0;
            
            default:
                break;
        }
    }
    
    
    
}
