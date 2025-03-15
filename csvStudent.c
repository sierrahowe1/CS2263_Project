#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 1024
#define MAXLEN 30
#include "student.h"
#include <ctype.h>

float calculateGPA(float grades[], int numGrades) {
    float total = 0.0;
    float average = 0;
    if (numGrades == 0) {
        printf("There are no grades associated with this student\n");
        return 0.0;
    }
    
    for (int i = 0; i < numGrades; i++) {
        total += grades[i]; 
    }
    
    average =  total / numGrades; 
    float GPA = (average / 100) * 4.3;
    return GPA;
}

int compare(const void* a, const void* b, int type) {
    Student* s1 = (Student*)a;
    Student* s2 = (Student*)b;
    int value;
    if (type == 1) {value = s1->id - s2->id;}
    else if (type == 2) {value = s1->GPA - s2->GPA;}
    else if (type == 3) {value = strcmp(s1->name, s2->name);}
    return value;
}


void merge(Student arr[], int l, int m, int r, int type) {
    int n1 = m - l + 1; 
    int n2 = r - m;    

    
    Student leftArr[n1];
    Student rightArr[n2];

    
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    
    
    while (i < n1 && j < n2) {
        if (compare(&leftArr[i], &rightArr[j], type) <= 0) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

char *trim(char *s) {
   int start = 0;
   int end = 0;
   
   while(isspace(s[start])) {
      start++;
   }
   
   while ((s[end] = s[start])) {
      start++;
      end++;
   }
   
   end--;
   while(end >= 0 && isspace(s[end])) {
      s[end] = '\0';
      end--;
   }
   return s;
}


void readData(const char *file, Student *student, int *numStudents) {
    char lines[MAXSIZE];

    FILE *input = fopen(file, "r");
    if (input == NULL) {
        perror("Could not open file");
        return;
    }

    while (fgets(lines, MAXSIZE, input) != NULL) {
        if (*numStudents >= 100) { 
            printf("Out of bounds.\n");
            break;
        }

        Student *stud = &student[*numStudents];
        char *del = strtok(lines, ","); 

        if (del == NULL) {
            printf("Invalid input file.\n");
            continue;
        }
        stud->id = atoi(del); 

        del = strtok(NULL, ","); 
        if (del == NULL) {
            printf("Invalid input file.\n");
            continue;
        }
        strncpy(stud->name, del, MAXLEN); 
        stud->name[MAXLEN - 1] = '\0'; 
        trim(stud->name);
        
        stud->numGrades = 0;
        while ((del = strtok(NULL, ",\n")) != NULL) {
            if (stud->numGrades >= MAXSIZEE) break;  

            
            strncpy(stud->classes[stud->numGrades], del, MAXLEN);
            stud->classes[stud->numGrades][MAXLEN - 1] = '\0';

            
            del = strtok(NULL, ",\n");
            if (del == NULL) {
                del = "0.00"; 
            }

            
            stud->grades[stud->numGrades] = atof(del);
            stud->numGrades++;
        }

        
        if (stud->numGrades > 0) {
            stud->GPA = calculateGPA(stud->grades, stud->numGrades);
        } else {
            stud->GPA = 0.0;  
        }
        (*numStudents)++;
    }
    fclose(input);
}

void mergeSort(Student arr[], int left, int right, int type) {
    if (left < right) {
        int mid = left + (right - left) / 2; 
        
        
        mergeSort(arr, left, mid, type);
        mergeSort(arr, mid + 1, right, type);

        
        merge(arr, left, mid, right, type);
    }
}


Student *searchName(Student arr[], char *name, int numStudents) {
   for(int i = 0; i < numStudents; i++) {
      if(strcasecmp(arr[i].name, name) == 0) {
         return &arr[i];
      }
   }
   return NULL;
}

Student *searchID(Student arr[], int Id, int numStudents) {
   for(int i = 0; i < numStudents; i++) {
      if(arr[i].id == Id) {
         return &arr[i];
      }
   }
   return NULL;

}


void searchForStudent(Student students[], int numStudents) {
   
   int choice;
   printf("1.) Name, 2.) ID\n");
   printf("Choose searching criteria: ");
   scanf("%d", &choice);
   
   
   for(int i = 0; i < numStudents; i++) {
      printf("%s\n", students[i].name);
   }
   
   
   
   if(choice == 1) {
      char name[MAXSIZEE];
      printf("Enter students name: ");
      scanf(" %[^\n]", name);
   
   
      Student *student = searchName(students, name, numStudents);
      if(student != NULL) {
         printf("Student successfully located!\n");
         printf("ID: %d, Name: %s, GPA: %.1f\n", student->id, trim(student->name), student->GPA);
      }
      else {
         printf("Student not found.\n");
      }
   
   }
   else if(choice == 2) {
      int id;
      printf("Enter student ID: ");
      scanf("%d", &id);
      
      Student *student = searchID(students, id, numStudents);
      if(student != NULL) {
         printf("Student successfully located:\n");
         printf("ID: %d, Name: %s, GPA: %.1f\n", student->id, student->name, student->GPA);
      }
      else {
         printf("Student not found.\n");
      }
      
   }
   else {
      printf("Must enter a valid choice\n");
   }
   
}


void writeData(Student *student, int numStudents) {
    FILE *output = fopen("studentGrades.csv", "w");
    if (output == NULL) {
        perror("Could not open file");
        return;
    }
    
    for (int i = 0; i < numStudents; i++) {
        Student *student1 = &student[i];

        fprintf(output, "%d, %s", student1->id, student1->name);

        
        for (int j = 0; j < student1->numGrades; j++) {
            fprintf(output, ", %s, %.1f", student1->classes[j], student1->grades[j]);
        }

        
        fprintf(output, ", GPA: %.1f\n", student1->GPA);
    }

    fclose(output);
}

