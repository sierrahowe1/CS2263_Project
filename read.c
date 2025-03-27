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

        // Initialize classes pointers to NULL
        for(int i = 0; i < MAXSIZEE; i++) {
            stud.classes[i] = NULL;
        }
        
        stud.numGrades = 0;
        while ((del = strtok(NULL, ",\n")) != NULL) {
            if (stud.numGrades >= MAXSIZEE) {
               printf("Grades are full");
               break;
            }  

            stud.classes[stud.numGrades] = (char *)malloc(MAXLEN * sizeof(char));
            if(stud.classes[stud.numGrades] == NULL) {
                printf("Could not allocate memory");
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
            for(int i = 0; i < stud.numGrades; i++) {
                if(stud.classes[i] != NULL) {
                    free(stud.classes[i]);
                }
            }
        } 
    }
    
    if(*numStudents == 0) {
       printf("This file is empty.\n");
    }
    
    fclose(input);
}
