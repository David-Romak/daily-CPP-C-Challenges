#include <iostream>
#include <string>
#include <cctype>

std::string replace_numbers(const std::string& input) {
    static const std::string words[] = {
        "zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine", "ten"
    };

    std::string output;

    for (size_t i = 0; i < input.size(); ) {
        // check for "10"
        if (input[i] == '1' && i + 1 < input.size() && input[i + 1] == '0') {
            output += words[10];
            i += 2;
        }
        // single digit 0–9
        else if (std::isdigit(static_cast<unsigned char>(input[i]))) {
            output += words[input[i] - '0'];
            i++;
        }
        // normal character
        else {
            output += input[i];
            i++;
        }
    }

    return output;
}

int main() {
    std::string input = "i need 2 pumpkins and 3 apples";
    std::string result = replace_numbers(input);

    std::cout << result << '\n';
    return 0;
}
