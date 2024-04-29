#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;

int main(int argc, char* argv[]) {
    string word = argv[1];
    cout << "Your word is: " << word << endl;
    cout << "It has " << word.size() << " characters." << endl;
    cout << "It's first letter is: " << word[0] << endl;
    cout << "It's last letter is: " << word[word.size()-1] << endl;
}