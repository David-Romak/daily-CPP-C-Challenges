#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char to_lower_char(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c - 'A' + 'a';
    }
    return c;
}

char get_last_char(const char *word)
{
    int len = strlen(word);
    if (len == 0)
        return '\0';

    int i = len - 1;
    while (i >= 0 && isspace(word[i]))
    {
        i--;
    }

    if (i >= 0)
    {
        return to_lower_char(word[i]);
    }
    return '\0';
}

char get_first_char(const char *word)
{
    int i = 0;
    while (word[i] && isspace(word[i]))
    {
        i++;
    }

    if (word[i])
    {
        return to_lower_char(word[i]);
    }
    return '\0';
}

bool check_sentence_flow(const char *sentence)
{

    if (sentence == NULL || sentence[0] == '\0')
    {
        return true;
    }

    int i = 0;
    int sentence_len = strlen(sentence);

    while (i < sentence_len && isspace(sentence[i]))
    {
        i++;
    }

    if (i >= sentence_len)
    {
        return true;
    }

    int word_start = i;
    while (i < sentence_len && !isspace(sentence[i]))
    {
        i++;
    }
    int word_end = i - 1;

    char last_char = to_lower_char(sentence[word_end]);

    while (i < sentence_len)
    {

        while (i < sentence_len && isspace(sentence[i]))
        {
            i++;
        }

        if (i >= sentence_len)
        {
            break;
        }

        word_start = i;

        while (i < sentence_len && !isspace(sentence[i]))
        {
            i++;
        }
        word_end = i - 1;

        char first_char = to_lower_char(sentence[word_start]);

        if (first_char != last_char)
        {
            return false;
        }

        last_char = to_lower_char(sentence[word_end]);
    }

    return true;
}

int main()
{
    // Test cases
    const char *test_sentences[] = {
        "this string gets stuck", // true
        "hello world",            // false
        "apple",                  // true (single word)
        "A apple",                // false ('e' != 'a')
        "bob bob",                // true ('b' == 'b')
        "cats sleep peacefully",  // false ('s' != 'l')
        "test test test",         // true ('t' == 't')
        "race car race",          // true ('e' == 'c', 'r' == 'r')
        "",                       // true (empty)
        "   hello   world   ",    // false
        "Ant Apple",              // false ('t' != 'a')
        "Ant ant",                // true ('t' == 'a') after lowercase
    };

    printf("Sentence Flow Checker\n");
    printf("=====================\n\n");

    for (int i = 0; i < sizeof(test_sentences) / sizeof(test_sentences[0]); i++)
    {
        printf("Sentence: \"%s\"\n", test_sentences[i]);
        printf("Result:   %s\n\n", check_sentence_flow(test_sentences[i]) ? "true" : "false");
    }

    return 0;
}