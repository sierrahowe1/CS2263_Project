//student.h
#ifndef STUDENT_H
#define STUDENT_H
#define MAXSIZEE 10
#define MAXLENGTH 1024

typedef struct
{
char name[MAXLENGTH];
int id;
float grades[MAXSIZEE];
int numGrades;
float GPA;

}Student;

#endif
