#include <string>
using std::string;

#include <iostream>
using std::cout, std::endl;

#include <map>
using std::map;

#include <set>
using std::set;

#include "input.h"

int main()
{
    // Get words
    map<size_t, set<string>> words_of_length;
    string word;
    while (input("Word: ", word))
    {
        auto key = word.size();
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