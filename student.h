//student.h
#ifndef STUDENT_H
#define STUDENT_H
#define MAXSIZEE 10
#define MAXLENGTH 1024

typedef struct StudentNode StudentNode;

typedef struct
{
int id;
char name[MAXLENGTH];
float grades[MAXSIZEE];
char classes[MAXSIZEE][MAXLENGTH];
int numGrades;
float GPA;

}Student;



typedef struct StudentNode{
   Student data;
   StudentNode *next;
   
}StudentNode;

#endif
