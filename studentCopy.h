//student.h
#ifndef STUDENT_H
#define STUDENT_H
#define MAXSIZEE 10


typedef struct StudentNode StudentNode;

typedef struct
{
int id;
char *name;
float *grades;
char *classes[MAXSIZEE];
int numGrades;
float GPA;

}Student;



typedef struct StudentNode{
   Student data;
   StudentNode *next;
   
}StudentNode;

#endif
