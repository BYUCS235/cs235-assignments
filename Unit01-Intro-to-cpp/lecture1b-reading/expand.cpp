#include <iostream>
using std::cout, std::endl, std::getline;

#include <fstream>
using std::ifstream;

#include <sstream>
using std::istringstream;

#include <string>
using std::string;

int main(int argc, char* argv[]) {
    ifstream file(argv[1]);
    string line;
    while (getline(file, line)) {
        istringstream linestream(line);
        string word;
        int count;
        linestream >> word >> count;
        for (int i = 0; i < count; i++) {
            cout << word << " ";
        }
        cout << endl;
    }
}