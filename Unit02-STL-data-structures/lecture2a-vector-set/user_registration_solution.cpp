#include <iostream>
using std::cout, std::endl, std::cin;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <unordered_set>
using std::unordered_set;


string input(string prompt) {
    cout << prompt;
    string response;
    getline(cin, response);
    return response;
}


int main() {
    vector<string> users;
    unordered_set<string> user_ids;

    while (true) {
        string uid = input("User ID: ");
        if (uid == "") { break; }

        if (user_ids.find(uid) != user_ids.end()) {
            cout << "That ID is already taken. Please pick another." << endl;
            continue;
        } else {
            user_ids.insert(uid);
        }


        string user = input("User first and last name: ");
        users.push_back(user + " (" + uid + ")");
    }

    cout << endl << "Registered Users" << endl;
    for (auto user : users) {
        cout << user << endl;
    }
}
