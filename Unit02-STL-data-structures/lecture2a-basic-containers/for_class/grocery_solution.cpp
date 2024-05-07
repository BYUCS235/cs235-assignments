// :)

#include <iostream>
using std::cout, std::endl, std::cin;

#include <string>
using std::string, std::getline;

#include <vector>
using std::vector;


bool input(string const& prompt, string& line) {
    cout << prompt;
    return getline(cin, line) && !line.empty();
}

int main() {
    vector<string> groceries;

    string item;
    while (input("Item: ", item)) {
        groceries.push_back(item);
    }
    
    for (auto const& item : groceries) {
        cout << "- " << item << endl;
    }

}