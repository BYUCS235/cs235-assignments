#include <string>
using std::string, std::getline;

#include <fstream>
using std::ifstream;

#include <unordered_map>
using std::unordered_map;

#include <iostream>
using std::cout, std::endl;

#include "debug.h"

void interpret(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        return;
    }

    /*
    var=val
    var
    */
    unordered_map<string, string> variables;

    string line;
    while (getline(file, line)) {
        TRACK(line)
        int equal_pos = line.find('=');
        TRACK(equal_pos)
        if (equal_pos == -1) {
            // just a var
            cout << variables[line] << endl;
        } else { 
            string varname = line.substr(0, equal_pos);
            TRACK(varname)
            string value = line.substr(equal_pos + 1, line.size()-equal_pos);
            TRACK(value)
            variables[varname] = value;
        }
    }
}

int main(int argc, char* argv[]) {
    interpret(argv[1]);
}