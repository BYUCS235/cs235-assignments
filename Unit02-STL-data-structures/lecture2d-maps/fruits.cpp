#include <string>
using std::string;

#include <iostream>
using std::cout, std::endl;

#include <map>
using std::map;

#include <set>
using std::set;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include "input.h"

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
        }
    }
    return count;
}

int main()
{
    // Get words
    map<char, set<string>> words_of_length;
    string word;
    while (input("Fruit: ", word))
    {
        auto key = count_vowels(word);
        // words_of_length[key].push_front(word);
        // words_of_length[key].push_back(word);
        words_of_length[key].insert(word);
    }

    // Print words
    for (auto const& entry : words_of_length)
    {
        cout << "Words of length " << entry.first << ":";
        for (auto const& word : entry.second)
        {
            cout << " " << word;
        }
        cout << endl;
    }
}