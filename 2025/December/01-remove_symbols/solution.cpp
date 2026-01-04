#include <iostream>

using namespace std;

string remove_symbols(const string& text){
    string result;

    for ( auto c: text){
        if(c == ' ' || isalnum(c))
        result+=c;
    }

    return result;

}

int main(){
    string text;
    cout << "Enter text: ";
    getline(cin , text);

    auto clean_text = remove_symbols(text);

    cout << "Clean Text: " <<  clean_text << endl;

    return 0;
}