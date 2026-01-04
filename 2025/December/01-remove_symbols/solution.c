#include <stdio.h>
#include <ctype.h>
#include <string.h>

void remove_symbols(char *text) {
    int j = 0;
    for (int i = 0; text[i] != '\0'; ++i)
        if (text[i] == ' ' || isalnum(text[i]))
            text[j++] = text[i];

    text[j] = '\0';
}

int main() {
    char str[1000];
    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);
    remove_symbols(str);
    printf("%s\n", str);

    return 0;
}
