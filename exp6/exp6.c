#include <stdio.h>
#include <string.h>

enum State {
    START,
    A,
    AB,
    ABB,
    B
};

int main() {
    char str[100];
    printf("Enter a String: ");
    scanf("%s", str);

    enum State state = START;
    for (int i = 0; i < strlen(str); i++) {
        switch (state) {
            case START:
                if (str[i] == 'a') state = A;
                else if (str[i] == 'b') state = B;
                else {
                    printf("String not accepted.\n");
                    return 0;
                }
                break;
            case A:
                if (str[i] == 'a') state = A;
                else if (str[i] == 'b') state = AB;
                else {
                    printf("String not accepted.\n");
                    return 0;
                }
                break;
            case AB:
                if (str[i] == 'b') state = ABB;
                else {
                    printf("String not accepted.\n");
                    return 0;
                }
                break;
            case ABB:
                printf("String is accepted under a*/ a*b+/ abb.\n");
                return 0;
            case B:
                printf("String not accepted.\n");
                return 0;
        }
    }

    if (state == A || state == B || state == ABB)
        printf("String is accepted under a*/ a*b+/ abb.\n");
    else
        printf("String not accepted.\n");

    return 0;
}
