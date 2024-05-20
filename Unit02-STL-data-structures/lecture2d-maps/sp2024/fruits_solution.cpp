#include <string>
using std::string;

#include <iostream>
using std::cout, std::endl;

#include <set>
using std::set;

#include <map>
using std::map;

#include <unordered_map>
using std::unordered_map;

#include "input.h"

int main() {
    unordered_map<char, set<string>> fruits;
    string fruit;
    while (input("Fruit: ", fruit)) {
        fruits[fruit[0]].insert(fruit);
    }

    for (auto const& entry : fruits) {
        cout << entry.first << ": ";
        for (auto const& fruit : entry.second) {
            cout << fruit << " ";
        }
        cout << endl;
    }
}