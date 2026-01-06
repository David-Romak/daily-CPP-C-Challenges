#include <stdio.h>
#include <ctype.h>

void replace_numbers(const char *input, char *output) {
    const char *words[] = {
        "zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine", "ten"
    };

    int i = 0, j = 0;

    while (input[i] != '\0') {
        // check for "10"
        if (input[i] == '1' && input[i + 1] == '0') {
            const char *w = words[10];
            for (int k = 0; w[k] != '\0'; k++)
                output[j++] = w[k];
            i += 2;
        }
        // single digit 0–9
        else if (isdigit((unsigned char)input[i])) {
            int num = input[i] - '0';
            const char *w = words[num];
            for (int k = 0; w[k] != '\0'; k++)
                output[j++] = w[k];
            i++;
        }
        // normal character
        else {
            output[j++] = input[i++];
        }
    }

    output[j] = '\0';
}

int main() {
    char input[] = "i need 2 pumpkins and 3 apples";
    char output[256];

    replace_numbers(input, output);

    printf("%s\n", output);
    return 0;
}
