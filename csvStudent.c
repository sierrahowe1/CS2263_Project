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
      perror("Could not open file");
      return EXIT_FAILURE;
   
   }
   
   while(fgets(lines, MAXSIZE, input) != NULL) {
      Student *stud = &student[*numStudents];
      char *del = strtok(lines, ",");//stores the student id
      
      stud->id = atoi(del);//set the id element in the struct to be the integer equivalent to what is in del currently
      
      del = strtok(NULL, ",");//stores the students name
      strncpy(stud->name, del, MAXLENGTH);//copies the name into the name element of the struct
      
      stud->numGrades = 0;
      while(stud->numGrades < 10) {//checking if the number of grades is less than the max grades allowed
         stud->grades[stud->numGrades] = atof(del); //changing the grades from ASCII to float and setting the grades element to be equal to the grades at different positions
         stud->numGrades++; 
      }
       
       
      stud->GPA = calculateGPA(stud->grades, stud->numGrades);//setting the GPA element of the struct to be a function all to calculateGPA
       
      (*numStudents)++;//incrementing the number of students
      
   
   
   }
   
   fclose(input);
   return EXIT_SUCCESS;
   
}

void writeData(Student *student, int numStudents) {
   FILE *output = fopen("studentGrades.txt", "w");
   if(output == NULL) {
      perror("Could not open file");
      return EXIT_FAILURE;
   }
   
   for(int i = 0; i < numStudents; i++) {
      Student *student1 = &student[i];
      fprintf(output, "%d,%s", student1->id, student1->name);//printing id and name of the students to the file
      
      for(int j = 0; j < student1->numGrades; j++) {
         fprintf(output, ",%.2f", s->grades[j]);
      }
      fprintf("\n");
   
   }
   
   fclose(output);
   return EXIT_SUCCESS;



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














