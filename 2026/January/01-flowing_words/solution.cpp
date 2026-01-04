#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

char toLowerChar(char c)
{
    return static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
}

bool checkSentenceFlowStringStream(const string &sentence)
{
    stringstream ss(sentence);
    string word;
    vector<string> words;

    while (ss >> word)
    {
        words.push_back(word);
    }

    if (words.size() <= 1)
    {
        return true;
    }

    for (size_t i = 1; i < words.size(); i++)
    {
        const string &prev = words[i - 1];
        const string &curr = words[i];

        if (prev.empty() || curr.empty())
        {
            continue;
        }

        char prevLast = toLowerChar(prev.back());
        char currFirst = toLowerChar(curr.front());

        if (prevLast != currFirst)
        {
            return false;
        }
    }

    return true;
}

bool checkSentenceFlowIterative(const string &sentence)
{
    auto it = sentence.begin();
    auto end = sentence.end();

    while (it != end && isspace(*it))
    {
        ++it;
    }

    if (it == end)
    {
        return true;
    }

    auto word_start = it;
    while (it != end && !isspace(*it))
    {
        ++it;
    }

    char last_char = toLowerChar(*(it - 1));

    while (it != end)
    {

        while (it != end && isspace(*it))
        {
            ++it;
        }

        if (it == end)
        {
            break;
        }

        word_start = it;

        while (it != end && !isspace(*it))
        {
            ++it;
        }

        char first_char = toLowerChar(*word_start);

        if (first_char != last_char)
        {
            return false;
        }

        last_char = toLowerChar(*(it - 1));
    }

    return true;
}

#if __cplusplus >= 202002L
#include <ranges>
bool checkSentenceFlowRanges(const string &sentence)
{
    auto words = sentence | std::views::split(' ') | std::views::transform([](auto &&word_range)
                                                                           { return std::string(word_range.begin(), word_range.end()); }) |
                 std::views::filter([](const string &w)
                                    { return !w.empty(); });

    string prev_word;
    for (const auto &word : words)
    {
        if (!prev_word.empty())
        {
            if (toLowerChar(prev_word.back()) != toLowerChar(word.front()))
            {
                return false;
            }
        }
        prev_word = word;
    }
    return true;
}
#endif

bool charsMatchCaseInsensitive(char a, char b)
{
    return toLowerChar(a) == toLowerChar(b);
}

int main()
{
    cout << "Sentence Flow Checker - C++ Implementation\n";
    cout << "==========================================\n\n";

    vector<pair<string, bool>> test_cases = {
        {"this string gets stuck", true},
        {"hello world", false},
        {"apple", true},
        {"A apple", false},
        {"bob bob", true},
        {"cats sleep peacefully", false},
        {"test test test", true},
        {"race car race", true},
        {"", true},
        {"   hello   world   ", false},
        {"Ant Apple", false},
        {"Ant ant", true},
        {"flow works seamlessly", true},
    };

    for (const auto &[sentence, expected] : test_cases)
    {
        cout << "Sentence: \"" << sentence << "\"" << endl;

        bool result1 = checkSentenceFlowStringStream(sentence);
        bool result2 = checkSentenceFlowIterative(sentence);

        cout << "Method 1 (stringstream): " << (result1 ? "true" : "false") << endl;
        cout << "Method 2 (iterative):    " << (result2 ? "true" : "false") << endl;

#if __cplusplus >= 202002L
        bool result3 = checkSentenceFlowRanges(sentence);
        cout << "Method 3 (ranges):       " << (result3 ? "true" : "false") << endl;
#endif

        cout << "Expected:                " << (expected ? "true" : "false") << endl;
        cout << "Status:                  " << (result1 == expected ? "✓ PASS" : "✗ FAIL") << endl;
        cout << endl;
    }

    cout << "\nEnter a sentence to check (or 'quit' to exit):\n";
    string input;
    while (true)
    {
        cout << "> ";
        getline(cin, input);

        if (input == "quit" || input == "exit")
        {
            break;
        }

        bool result = checkSentenceFlowStringStream(input);
        cout << "Result: " << (result ? "true" : "false") << endl;

        if (!input.empty())
        {
            stringstream ss(input);
            string prev_word, curr_word;

            if (ss >> prev_word)
            {
                cout << "Analysis: ";
                while (ss >> curr_word)
                {
                    char prev_last = toLowerChar(prev_word.back());
                    char curr_first = toLowerChar(curr_word.front());

                    cout << "\"" << prev_word << "\" → \"" << curr_word << "\": ";
                    cout << "'" << prev_last << "' " << (prev_last == curr_first ? "==" : "!=");
                    cout << " '" << curr_first << "'";

                    if (prev_last != curr_first)
                    {
                        cout << " ✗";
                    }
                    else
                    {
                        cout << " ✓";
                    }
                    cout << ", ";

                    prev_word = curr_word;
                }
                cout << endl;
            }
        }
        cout << endl;
    }

    return 0;
}