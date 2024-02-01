#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_LINE_LENGTH 1000

int isStopWord(char *word, FILE *stopWordsFile) {
    char stopWord[MAX_WORD_LENGTH];
    
    rewind(stopWordsFile);

    while (fscanf(stopWordsFile, "%s", stopWord) != EOF) {
        if (strcmp(word, stopWord) == 0) {
            return 1; 
        }
    }

    return 0;
}

void processStoryFile(FILE *storyFile, FILE *stopWordsFile, FILE *outputFile) {
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, storyFile) != NULL) {
        char *word = strtok(line, " \t\n"); 

        while (word != NULL) {
            if (!isStopWord(word, stopWordsFile)) {
                fprintf(outputFile, "%s ", word); 
            }

            word = strtok(NULL, " \t\n"); 
        }
        fprintf(outputFile, "\n"); 
    }
}

int main() {
    FILE *storyFile, *stopWordsFile, *outputFile;

    storyFile = fopen("story.txt", "r");
    if (storyFile == NULL) {
        printf("Unable to open story.txt for reading.\n");
        exit(1);
    }
    printf("Reading story.txt...\n");

    stopWordsFile = fopen("stop_words.txt", "r");
    if (stopWordsFile == NULL) {
        printf("Unable to open stop_words.txt for reading.\n");
        fclose(storyFile);
        exit(1);
    }
    printf("Reading stop_words.txt...\n");

    outputFile = fopen("story_without_stopwords.txt", "w");
    if (outputFile == NULL) {
        printf("Unable to create story_without_stopwords.txt for writing.\n");
        fclose(storyFile);
        fclose(stopWordsFile);
        exit(1);
    }

    processStoryFile(storyFile, stopWordsFile, outputFile);

    fclose(storyFile);
    fclose(stopWordsFile);
    fclose(outputFile);

    printf("Stop words removed successfully. Result saved in story_without_stopwords.txt.\n");

    return 0;
}
