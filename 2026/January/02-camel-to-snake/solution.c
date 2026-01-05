/*
- loop throgh every character , if uppercase replace with '_lowercase'
- return the new string
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char *camel_to_snake(const char *camel_string)
{
    size_t string_length = strlen(camel_string);
    char *snake_string = malloc(string_length * 2 + 1);

    char c;
    int j = 0;

    for (int i = 0; (c = camel_string[i]) != '\0'; i++)
    {
        if (isupper((unsigned char)c))
        {
            snake_string[j++] = '_';
            snake_string[j++] = tolower(c);
            continue;
        }

        snake_string[j++] = c;
    }

    snake_string[j] = '\0';

    return snake_string;
}

int main()
{
    char *snake = camel_to_snake("camelCaseExampleOne");
    printf("%s\n", snake);
    free(snake);

    return 0;
}
