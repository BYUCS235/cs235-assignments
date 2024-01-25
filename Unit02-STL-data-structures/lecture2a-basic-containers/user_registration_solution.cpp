// :)


#include <unordered_set>
using std::unordered_set;

#include <string>
using std::string, std::getline;

#include <iostream>
using std::cout, std::endl, std::cin;

#include <vector>
using std::vector;

bool input(string const& prompt, string& line) {
    cout << prompt;
    return getline(cin, line) && !line.empty();
}


int main() {
    vector<string> users;
    unordered_set<string> ids;

    string id;
    while (input("ID: ", id)) {
        auto ret = ids.insert(id);
        if (!ret.second) { cout << "That ID is already taken" << endl; continue; }

        string name;
        cout << "Name: ";
        getline(cin, name);
        users.push_back(name + " (" + id + ")");
    }

    for (auto const& name : users) {
        cout << name << endl;
    }
}