#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXZISIZE 1024
#define MAXLENGTH 30
#include "student.h"

void readData(const char *file, Student *student, int *numStudents) {
   char lines[MAXSIZE];
   
   FILE *input = fopen(file, "r");
   if(input == NULL) {
      printf("Could not open file");
      return EXIT_FAILURE;
   
   }
   
   while(fgets(lines, MAXSIZE, input) != NULL) {
      Student *stud = &student[*numStudents];
      char *del = strtok(lines, ",");//stores the student id
      
      stud->id = atoi(del);//set the id element in the struct to be the integer equivalent to what is in del currently
      
      del = strtok(NULL, ",");//stores the students name
      strncpy(stud->name, del, MAXLENGTH);//copies the name into the name element of the struct
       
       
      
       
      stud->GPA = calculateGPA(stud->grades, s->numGrades);//setting the GPA element of the struct to be a function all to calculateGPA
       
      (*numStudents)++;//incrementing the number of students
      
   
   
   }
   
}

void writeData() {



}

float calculateGPA(float grades[], int numGrades) {//calculating GPA
   float total = 0.0;
   float GPA;
   if(numGrades == 0) {
      printf("There are no grades associated with this student");
      return EXIT_FAILURE;
   }
   
   for(int i = 0; i < numGrades; i++) {
      total += grades[i];//adding each grade to the total to create a sum
   }
   
   GPA = total/numGrades;//calculating GPA
   return GPA;
   
}














