#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

string camel_to_snake(const string &camel)
{
    if (camel.empty())
        return "";

    string result;
    result.reserve(camel.length() * 2);

    result += tolower(camel[0]);

    for (size_t i = 1; i < camel.length(); i++)
    {
        char c = camel[i];
        if (isupper(c))
        {
            result += '_';
            result += tolower(c);
        }
        else
        {
            result += c;
        }
    }

    return result;
}

string camel_to_snake_stream(const string& camel) {
    if (camel.empty()) return "";
    
    stringstream ss;
    ss << (char)tolower(camel[0]);
    
    for (size_t i = 1; i < camel.length(); i++) {
        char c = camel[i];
        if (isupper(c)) {
            ss << '_' << (char)tolower(c);
        } else {
            ss << c;
        }
    }
    
    return ss.str();
}

int main()
{
    cout << "---CamelCase to Snake_Case Converter - C++---\n";
    string snake = camel_to_snake_stream("camelCase");
    cout << snake << endl;

    return 0;
}