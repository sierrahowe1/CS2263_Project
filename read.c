void readData(const char *file, StudentNode** head, int *numStudents) {
    char lines[MAXSIZE];
    FILE *input = fopen(file, "r");
    if (input == NULL) {
        perror("Could not open file");
        return;
    }

    while (fgets(lines, MAXSIZE, input) != NULL && *numStudents < 100) {
        Student stud = {0};
        char *del = strtok(lines, ",");
        if (del == NULL) continue;
        stud.id = atoi(del);

        del = strtok(NULL, ",");
        if (del == NULL) continue;
        stud.name = strdup(del);
        if(stud.name == NULL) continue;
        trim(stud.name);
        
        stud.grades = malloc(MAXSIZEE * sizeof(float));
        if(stud.grades == NULL) {
            free(stud.name);
            continue;
        }

        stud.numGrades = 0;
        while ((del = strtok(NULL, ",\n")) != NULL && stud.numGrades < MAXSIZEE) {
            stud.classes[stud.numGrades] = malloc(MAXLEN * sizeof(char));
            if(stud.classes[stud.numGrades] == NULL) {
                for(int i = 0; i < stud.numGrades; i++) free(stud.classes[i]);
                free(stud.grades);
                free(stud.name);
                stud.numGrades = 0;
                break;
            }
            strncpy(stud.classes[stud.numGrades], del, MAXLEN);
            stud.classes[stud.numGrades][MAXLEN - 1] = '\0';

            del = strtok(NULL, ",\n");
            stud.grades[stud.numGrades] = (del != NULL) ? atof(del) : 0.0f;
            stud.numGrades++;
        }

        stud.GPA = calculateGPA(stud.grades, stud.numGrades);

        if(searchID(head, stud.id) == NULL) {
            addStudent(head, stud);
            (*numStudents)++;
        }
        else {
            free(stud.name);
            free(stud.grades);
            for(int i = 0; i < stud.numGrades; i++) {
                free(stud.classes[i]);
            }
        }
    }
    
    fclose(input);
}
