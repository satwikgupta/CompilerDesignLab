#include <stdio.h>
#include <stdbool.h>
#include<string.h>

void extract_comments(char *input_file, char *output_file) {
    FILE *in = fopen(input_file, "r");
    FILE *out = fopen(output_file, "w");
    bool in_comment = false;
    char line[1024];

    while (fgets(line, sizeof(line), in) != NULL) {
        char *stripped = line;
        while (*stripped == ' ' || *stripped == '\t') stripped++;

        if (strncmp(stripped, "/*", 2) == 0) {
            in_comment = true;
        }

        if (in_comment || strncmp(stripped, "//", 2) == 0) {
            fputs(line, out);
        }

        if (strstr(stripped, "*/") != NULL) {
            in_comment = false;
        }
    }

    fclose(in);
    fclose(out);
}

int main() {
    extract_comments("input.c", "comments.txt");
    return 0;
}
