#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXSIZE 1024
#define MAXLEN 30
#include "studentCopy.h"
#include <ctype.h>

float fmodf(float x, float y);


void addStudent(StudentNode** head, Student newStudent) {
   StudentNode *node = (StudentNode *)malloc(sizeof(StudentNode));
   if(node == NULL) {
      printf("Could not allocate memory");
      return;
   }
   node->data = newStudent;
   node->next = NULL;
   
   if(*head == NULL) {
      *head = node;
   }
   else {
      StudentNode *current = *head;
      while(current->next != NULL) {
         current = current->next;
      }
      current->next = node;
   }

}

void removeStudent(StudentNode **head, int id) {
   StudentNode *node = *head;
   if(*head == NULL) {
      return;
   }
   if(node->data.id == id) {
      
      *head = (*head)->next;
      
      free(node->data.name);
      free(node->data.grades);
      for(int i = 0; i < node->data.numGrades; i++) {
         free(node->data.classes[i]);
      }
      free(node);
   }
   
   StudentNode *otherNode = *head;
   while((node != NULL) && (node->data.id) != id) {
      otherNode = otherNode->next;
      node = node->next;
   }
   if(node != NULL) {
      node = otherNode->next;
      otherNode->next = node->next;
      
      free(node->data.name);
      free(node->data.grades);
      for(int i = 0; i < node->data.numGrades; i++) {
         free(node->data.classes[i]);
      }
      free(node);
   }
   
}


float calculateGPA(float grades[], int numGrades) {
    float total = 0.0;
    float average = 0;
    if (numGrades == 0) {
        printf("There are no grades associated with this student\n");
        return 0.0;
    }
    
    
    for (int i = 0; i < numGrades; i++) {
       if(grades[i] > 100 || grades[i] < 0) {
          printf("Invalid grade detected.\n");
          return 0.0;
       }
       else {
          total += grades[i]; 
       }
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
    else if (type == 2) {
                         if(fabs(s1->GPA - s2->GPA) < 0.00001f) {
                            value = 0;
                         } else if (s1->GPA < s2->GPA) {
                           value = -1; 
                         } else {
                           value = 1; 
                         }}
    else if (type == 3) {value = strcmp(s1->name, s2->name);}
    return value;
}


StudentNode *merge(StudentNode *node1, StudentNode *node2, int type) {
   if(node1 == NULL) {
      return node2;
   }
   if(node2 == NULL) {
      return node1;
   }
   
   if(compare(&node1->data, &node2->data, type) <= 0) {
      node1->next = merge(node1->next, node2, type);
      return node1;
   }
   else {
      node2->next = merge(node1, node2->next, type);
      return node2;
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


Student *searchID(StudentNode **head, int Id) {
   StudentNode *current = *head;
   while(current != NULL) {
      if(current->data.id == Id) {
         return &current->data;
      }
      current = current->next;
   }
   return NULL;

}



void readData(const char *file, StudentNode** head, int *numStudents) {
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

        Student stud;
        char *del = strtok(lines, ","); 

        if (del == NULL) {
            printf("Invalid format.\n");
            continue;
            
        }
        stud.id = atoi(del); 

        del = strtok(NULL, ","); 
        if (del == NULL) {
            printf("Invalid format.\n");
            continue;
            
            
        }
        stud.name = (char *)malloc((strlen(del) + 1) * sizeof(char));
        if(stud.name == NULL) {
           printf("Could not allocate memory");
           continue;
        }
        strcpy(stud.name, del); 
        trim(stud.name);
        
        stud.grades = (float *)malloc(MAXSIZEE * sizeof(float));
        if(stud.grades == NULL) {
           printf("Could not allocate memory");
           free(stud.name);
           continue;
        }
        for(int i = 0; i < MAXSIZEE; i++) {
           stud.classes[i] = (char *)malloc(MAXLEN * sizeof(char));
           if(stud.classes[i] == NULL) {
              printf("Could not allocate memory");
              for(int j = 0; j < i; j++) {
                 free(stud.classes[j]);
              }
              free(stud.grades);
              free(stud.name);

           }
        }
        
        stud.numGrades = 0;
        while ((del = strtok(NULL, ",\n")) != NULL) {
            if (stud.numGrades >= MAXSIZEE) {
               printf("Grades are full");
               break;
            }  

            
            strncpy(stud.classes[stud.numGrades], del, MAXLEN);
            stud.classes[stud.numGrades][MAXLEN - 1] = '\0';

            
            del = strtok(NULL, ",\n");
            if (del == NULL) {
                del = "0.0";
                
            }

            
            stud.grades[stud.numGrades] = atof(del);
            stud.numGrades++;
        }

        
        if (stud.numGrades > 0) {
            stud.GPA = calculateGPA(stud.grades, stud.numGrades);
        } else {
            stud.GPA = 0.0;  
        }
        if(searchID(head, stud.id) == NULL) {
           addStudent(head, stud);
           (*numStudents)++;
        }
        else {
           printf("Duplicate student entry found!");
           free(stud.name);
           free(stud.grades);
           for(int i = 0; i < MAXSIZEE; i++) {
              free(stud.classes[i]);
           }
        } 
        
    }
    
    
    if(*numStudents == 0) {
       printf("This file is empty.\n");
    }
    
    
    fclose(input);
}

void split(StudentNode *head, StudentNode **a, StudentNode **b) {
   StudentNode *fast = head;
   StudentNode *slow = head;
   
   while(fast != NULL && fast->next != NULL) {
      fast = fast->next->next;
      if(fast != NULL) {
         slow = slow->next;
      }
   }
   
   *a = head;
   *b = slow->next;
   slow->next = NULL;
}


void mergeSort(StudentNode** head, int type) {
   StudentNode *head2 = *head;
   StudentNode *a;
   StudentNode *b;
   
   if(head2 == NULL || head2->next == NULL) {
      return;
   }
   
   split(head2, &a, &b);
   mergeSort(&a, type);
   mergeSort(&b, type);
   
   *head = merge(a, b, type);
       
}


void printBarChart(Student *student) {
   int numBars;
   for(int i = 0; i < student->numGrades; i++) {
      printf(" %s |", student->classes[i]);
         if(student->grades[i] > 0 && student->grades[i] < 100) {
            numBars = fmodf((student->grades[i])/10, 10);
         }
         else if(student->grades[i] == 100) {
            numBars = (student->grades[i])/10;
         }
         else {
            printf("Invalid grade found");
            break;
         }
      
      for(int j = 0; j < numBars; j++) {
         printf("#");
      }
      printf(" (%.1f)\n", student->grades[i]);
   }
   
   
}


Student *searchName(StudentNode **head, char *name) {
   StudentNode *current = *head;
   while(current != NULL) {
      if(strcasecmp(current->data.name, name) == 0) {
         return &current->data;
      }
      current = current->next;
   }
   return NULL;
}


void searchForStudent(StudentNode **head, int numStudents) {
   
   int choice;
   printf("1.) Name, 2.) ID\n");
   printf("Choose searching criteria: ");
   scanf("%d", &choice);
   
   
   
   if(choice == 1) {
      char name[MAXSIZEE];
      printf("Enter students name: ");
      scanf(" %[^\n]", name);
   
   
      Student *student = searchName(head, name);
      if(student != NULL) {
         printf("\n");
         printf("Student successfully located!\n");
         printf("\n");
         printf("ID: %d, Name: %s, GPA: %.1f\n", student->id, trim(student->name), student->GPA);
         printBarChart(student);
      }
      else {
         printf("Student not found.\n");
      }
   
   }
   else if(choice == 2) {
      int id;
      printf("Enter student ID: ");
      scanf("%d", &id);
      
      Student *student = searchID(head, id);
      if(student != NULL) {
         printf("Student successfully located:\n");
         printf("ID: %d, Name: %s, GPA: %.1f\n", student->id, student->name, student->GPA);
         printBarChart(student);
      }
      else {
         printf("Student not found.\n");
      }
      
   }
   else {
      printf("Must enter a valid choice\n");
   }
   
}


void writeData(StudentNode** head, int numStudents) {
    FILE *output = fopen("studentGrades.csv", "w");
    if (output == NULL) {
        perror("Could not open file");
        return;
    }
    
    StudentNode *current = *head;
    
    while(current != NULL) {
       fprintf(output, "%d, %s", current->data.id, current->data.name);
       for (int j = 0; j < current->data.numGrades; j++) {
            fprintf(output, ", %s, %.1f", current->data.classes[j], current->data.grades[j]);
        }
        fprintf(output, ", GPA: %.1f\n", current->data.GPA);
        current = current->next;
        
    
    }
    if(*head == NULL) {
       printf("Could not write data");
    }
    else {
       printf("Successfully wrote data");
    }
    fclose(output);
}

void freeList(StudentNode** head) {
   while(*head != NULL) {
      StudentNode *current = (*head)->next;
      
      free((*head)->data.name);
      free((*head)->data.grades);
      for(int i = 0; i < (*head)->data.numGrades; i++) {
         free((*head)->data.classes[i]);
      }
      free(*head);
      *head = current;
   }

}
