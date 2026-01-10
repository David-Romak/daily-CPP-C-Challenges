#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string decompress(const string &text) {
    string result;

    for (size_t i = 1; i < text.length(); ++i) {
        if (isdigit(static_cast<unsigned char>(text[i]))) {
            result.append(text[i] - '0', text[i - 1]);
        }
    }

    return result;
}

int main() {
    string result = decompress("a3b5");
    cout << result << endl;
    return 0;
}
