#include <string>
using std::string, std::getline; 

#include <iostream>
using std::cout, std::cin, std::cerr, std::endl;

#include <queue>
using std::queue;

#include "input.h"

int main()
{
    queue<string> waiting;
    string action;
    while (input("Action: ", action))
    {
        if (action == "add")
        {
            input("Name: ", action);
            waiting.push(action);
        }
        else if (action == "next")
        {
            if (waiting.empty())
            {
                cout << "No one in line" << endl;
            }
            else
            {
                cout << waiting.front() << endl;
                waiting.pop();
            }
        }
        else
        {
            cerr << "Unsupported action: " << action << endl;
        }
    }
}