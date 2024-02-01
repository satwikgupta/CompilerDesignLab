#include <stdio.h>
#include <stdlib.h>

void deleteLine(const char *inputFilePath, const char *outputFilePath, int lineToDelete) {
    FILE *inputFile, *outputFile;
    char buffer[1000];
    int currentLine = 0;

    // Open input file for reading
    inputFile = fopen(inputFilePath, "r");
    if (inputFile == NULL) {
        printf("Unable to open input file!\n");
        exit(1);
    }

    // Open output file for writing
    outputFile = fopen(outputFilePath, "w");
    if (outputFile == NULL) {
        printf("Unable to open output file!\n");
        fclose(inputFile);
        exit(1);
    }

    // Read lines from the input file and skip the specified line
    while (fgets(buffer, sizeof(buffer), inputFile) != NULL) {
        currentLine++;
        
        if (currentLine != lineToDelete) {
            fputs(buffer, outputFile);
        }
    }

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    // Rename the output file to the input file
    remove(inputFilePath);
    rename(outputFilePath, inputFilePath);

    printf("Line %d deleted successfully.\n", lineToDelete);
}

int main() {
    char inputFilePath[100], outputFilePath[100];
    int lineToDelete;

    printf("Enter the path of the text file: ");
    scanf("%s", inputFilePath);

    printf("Enter the line number to delete: ");
    scanf("%d", &lineToDelete);

    // Generate a temporary output file path
    snprintf(outputFilePath, sizeof(outputFilePath), "%s_tmp", inputFilePath);

    deleteLine(inputFilePath, outputFilePath, lineToDelete);

    return 0;
}
