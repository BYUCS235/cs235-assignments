#include <string>
using std::string;

#include <iostream>
using std::cout, std::endl;

#include <map>
using std::map;

#include "input.h"

int main()
{
    map<string, int> counts;
    string name;
    while (input("Month: ", name))
    {
        counts[name]++;
    }

    // Print the scores
    cout << endl
         << "Counts" << endl
         << "-------------" << endl;
    for (auto &entry : counts)
    {
        cout << entry.first << ": " << entry.second << endl;
    }
}
