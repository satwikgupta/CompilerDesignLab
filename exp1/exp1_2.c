#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n, marks;
    char name[60], path[100];

    printf("\nEnter the source file's path: ");
    scanf("%s", path);

    FILE *file;
    file = fopen(path, "w");
    if(file == NULL) {
        printf("\nUnable to open!\n");
        exit(1);
    }

    printf("\nEnter the number of students: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        fflush(stdin);
        printf("For student %d:\n\tName: ", (i + 1));
        scanf("%[^\n]s", name);
        printf("\tMarks: ");
        scanf("%d", &marks);

        fprintf(file, "Student %d:-\n\tName: %s\n\tMarks: %d\n", (i + 1), name, marks);
    }
    
    fclose(file);
    printf("Data has been successfully written to the file.\n");
    return 0;
}