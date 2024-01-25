#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

int main() {
    vector<string> words = {"one", "fish", "two", "fish"};

    vector<string> more_words;
    more_words.push_back("red");
    more_words.push_back("fish");
    more_words.push_back("blue");
    more_words.push_back("fish");

    for (int i = 0; i < words.size(); i++) {
        cout << words[i] << endl;
    }

    for (int i = 0; i < more_words.size(); i++) {
        cout << more_words.at(i) << endl;
    }
    
    cout << endl << "One more time!" << endl;
    for (string word : words) {
        cout << word << endl;
    }

    for (auto word : more_words) {
        cout << word << endl;
    }    
}