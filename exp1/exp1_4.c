#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourceFile, *destinationFile;
    char sourcePath[100], destinationPath[100];
    char ch;

    printf("Enter the source file path: ");
    scanf("%s", sourcePath);

    sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        printf("Unable to open source file!\n");
        exit(1);
    }

    printf("Enter the destination file path: ");
    scanf("%s", destinationPath);

    destinationFile = fopen(destinationPath, "w");
    if (destinationFile == NULL) {
        fclose(sourceFile);
        printf("Unable to open destination file!\n");
        exit(1);
    }

    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destinationFile);
    }

    fclose(sourceFile);
    fclose(destinationFile);

    printf("Content copied successfully from '%s' to '%s'.\n", sourcePath, destinationPath);

    return 0;
}
