#include <string>
using std::string;

#include <iostream>
using std::cout, std::endl;

#include "input.h"
using handy::input;

int main() {
    while (true) {
        string phrase = input("Phrase: ");
        if (!phrase.size()) { break; }  
        
        for (char c : phrase) {
            if (c >= 'A' && c <= 'Z') {
                cout << c << endl;
            }
        }
    }
}