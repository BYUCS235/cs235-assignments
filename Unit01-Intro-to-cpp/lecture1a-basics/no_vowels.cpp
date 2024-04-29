#include <string>
using std::string;

#include <iostream>
using std::cout, std::endl;

#include <sstream>
using std::ostringstream;

const string VOWELS = "aeiouAEIOU";

string no_vowels(string text) {
    ostringstream result;
    for (size_t pos = 0; pos < text.size(); pos++) {
        if (VOWELS.find(text[pos]) != -1) {
            continue;
        }
        result << text[pos];
    }
    return result.str();
}

int main(int argc, char* argv[]) {
    for (int arg = 1; arg < argc; arg++) {
        cout << no_vowels(argv[arg]) << endl;
    }
}