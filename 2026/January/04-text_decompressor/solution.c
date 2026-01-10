#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *decompress(char *text) {\
    char *decompressed_text = malloc(100);
    int j = 0;

    for (int i = 1; i < strlen(text); ++i) {
        if (isdigit(text[i])) {
            for (int x = 0; x < text[i] - '0'; ++x)
                decompressed_text[j++] = text[i - 1];
        }
    }

    decompressed_text[j] = '\0';

    return decompressed_text;
}

int main() {
    char *rst = decompress("k2c4");
    printf("%s", rst);
    free(rst);
}
