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
    int choice;
    
    printf("\n --!Welcome to S&J Student Grade Management System!--\n");
    printf("\n We offer a variety of services, please check out out menu below \n");
    
    do {
        printf("\nMenu:\n");
        printf("1. Import student data from CSV\n");
        printf("2. Sort Students by criteria\n");
        printf("3. Export students to a CSV with GPA calculated\n");
        printf("4. Exit\n");
        printf("\nWhat would you like to do today: ");
        scanf("%d", &choice);
       
        if (choice == 1) {
            readData("student.csv", stud, &numStudents);
            printf("Successfully imported students grades\n");
        } else if (choice == 2) {
            printf("\n --How do you want to sort the students:\n 1.) ID\n 2.) GPA\n 3.) Name\n ");
            printf("Choice of sort: ");
            scanf("%d", &type);
            mergeSort(stud, 0, numStudents-1, type);
            printf("Sorted!\n");
        } else if (choice == 3) {
            writeData(stud, numStudents);
            printf("Successfully exported students grades with GPA to studentGrades.csv\n");
        } 
    } while (choice != 4);
     printf("\nThank you for using our system! Have a lovely day\n");
     printf("\n");
     return 0;
}
