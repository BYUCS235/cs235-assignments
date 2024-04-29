#include <iostream>
using std::cout, std::cerr, std::cin, std::endl;

#include <string>
using std::string;

int main()
{
    cout << "add, replace, or quit: ";
    string operation;
    while (cin >> operation)
    {
        if (operation == "quit")
        {
            return 0;
        }
        else if (operation == "add")
        {
            string a;
            string b;
            cout << "Give me two words: ";
            cin >> a >> b;
            cout << a + b << endl;
        }
        else if (operation == "replace")
        {
            string word;
            size_t pos;
            string with;
            cout << "Give me a word: ";
            cin >> word;
            cout << "Replace string at pos: ";
            cin >> pos;
            cout << "With string: ";
            cin >> with;
            cout << word.replace(pos, with.size(), with) << endl;
            cout << word << endl;
        }
        else
        {
            cerr << "Unrecognized operation: " << operation << endl;
        }
        cout << "add, replace, or quit: ";
    }
    cout << "all done!" << endl;
}