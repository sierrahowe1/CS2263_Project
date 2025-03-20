#ifndef FILE_H
#define FILE_H




typedef struct {
   char *name;
   int size;
   Directory *parent;
}File;

typedef struct { 
   char *name;
   Directory *parent;
   Dirctory *child;
   Directory *siblings;
   File *file;
}Directory;
#endif
