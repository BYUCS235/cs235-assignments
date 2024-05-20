#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(vector<string> words) {
    for (string word : words) {
        cout << word << endl;
    }
}

vector<string> get_perms(string letters) {
    vector<string> perms;
    if (letters.length() == 1) {
        perms.push_back(letters);
    } else {
        for (int i = 0; i < letters.length(); i++) {
            char c = letters[i];
            string not_c = letters.substr(0, i) + letters.substr(i + 1);
            for (string sub_perm: get_perms(not_c)) {
                perms.push_back(c + sub_perm);
            }
        }
    }
    cout << "Letters are: " << letters << endl;
    print(perms);
    return perms;
}

int main(int argc, char* argv[]) {
    print(get_perms(argv[1]));
}