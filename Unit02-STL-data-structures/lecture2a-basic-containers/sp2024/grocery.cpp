#include <iostream>
using std::cout, std::endl, std::cin;

#include <string>
using std::string, std::getline;

#include <vector>
using std::vector;


int main() {
    string line;
    vector<string> items;
    cout << "Item: ";
    while (getline(cin, line) && line != "") {
        items.push_back(line);
        cout << "Item: ";
    }

    for (auto const& item : items) {
        cout << "- " << item << endl;
    }
}