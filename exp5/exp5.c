#include <stdio.h>
#include <string.h>

int main() {
    char input[10];
    printf("Enter an input: ");
    scanf("%s", input);

    if (strcmp(input, "+") == 0) {
        printf("Plus\n");
    } else if (strcmp(input, "-") == 0) {
        printf("Minus\n");
    } else if (strcmp(input, "*") == 0) {
        printf("Multiplication\n");
    } else if (strcmp(input, "/") == 0) {
        printf("Division\n");
    } else if (strcmp(input, "%") == 0) {
        printf("Modulus\n");
    } else {
        printf("Not an operator\n");
    }

    return 0;
}
