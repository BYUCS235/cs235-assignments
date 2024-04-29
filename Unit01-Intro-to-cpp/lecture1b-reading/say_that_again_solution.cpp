#include <iostream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

#include <string>
using std::string;
using std::getline;

#include "input.h"

int main() {
    string word;
    int times;

    while (true) {
        word = input("Enter a word: ");

        if (word.size() == 0) {
            return 0;
        }

        string response = input("How many times? ");
        times = std::stoi(response);
        
        for (int i = 0; i < times; i++) {
            cout << word << " ";
        }
        cout << endl;
    }
}