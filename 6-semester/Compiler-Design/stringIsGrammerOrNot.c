#include <stdio.h>
#include <string.h>

int main() {
    char string[50];
    int flag = 0, count = 0;

    printf("The grammar is:\n S->aS\n S->b\n");
    printf("Enter the string to be checked:\n");
    fgets(string, 50, stdin); 

    int length = strlen(string);
    if (string[length - 1] == '\n') 
        string[length - 1] = '\0'; 

    if (string[0] == 'b' && string[1] == '\0') {
        printf("String accepted…..!!!!\n");
        return 0;
    }

    if (string[0] == 'a') {
        for (count = 1; string[count] != '\0'; count++) {
            if (string[count] == 'b') {
                flag = 1;
            } else if (flag == 1 && string[count] == 'a') {
                printf("The string does not belong to the specified grammar\n");
                return 0;
            } else if (string[count] != 'a') {
                printf("String not accepted\n");
                return 0;
            }
        }

        if (flag == 1) {
            printf("String accepted\n");
        } else {
            printf("String not accepted\n");
        }
    } else {
        printf("String not accepted\n");
    }

    return 0;
}
