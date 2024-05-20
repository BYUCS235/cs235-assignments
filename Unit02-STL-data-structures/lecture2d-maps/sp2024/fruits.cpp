// :)

#include <string>
using std::string;

#include <map>
using std::map;

#include <set>
using std::set;

#include <iostream>
using std::cout, std::endl;

#include "input.h"  // input


int count_vowels(string const& word) {
    int count = 0;
    for (char c : word) {
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                count++;
            default:
                break;
        }
    }
    return count;
}


int main() {
    map<int, map<string, int>> fruits;

    string fruit;
    while (input("Fruit: ", fruit)) {
        auto key = count_vowels(fruit);
        fruits[key][fruit]++;
    }

    for (auto const& kvp : fruits) {
        cout << kvp.first << ": ";
        for (auto const& entry : kvp.second) {
            cout << entry.first << "(" << entry.second << ") ";
        }
        cout << endl;
    }
}