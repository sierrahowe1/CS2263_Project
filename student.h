//student.h
#ifndef STUDENT_H
#define STUDENT_H
#define MAXSIZE 10
#define MAXLENGTH 1024

typedef struct
{
char *name[MAXLENGTH];
int id;
float grades[MAXSIZE];
float GPA;

}Student

