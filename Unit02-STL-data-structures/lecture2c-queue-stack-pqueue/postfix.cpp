#include <string>
using std::string, std::getline, std::stoi, std::stod;

#include <sstream>
using std::stringstream;

#include <iostream>
using std::cout, std::cin, std::cerr, std::endl;

#include <stack>
using std::stack;

#include "input.h"

double calc(string const& expression) {
    stack<double> pending;
    stringstream ss(expression);
    string token;
    while (ss >> token) {
        if (isdigit(token[0])) {
            // First char is a number -> assume the whole thing is a number
            double val = stod(token);
            pending.push(val);
            
        } else {
            double a = pending.top();
            pending.pop();
            
            double b = pending.top();
            pending.pop();
            
            if (token == "+") {
                pending.push(b + a);

            } else if (token == "*") {
                pending.push(b * a);

            } else if (token == "-") {
                pending.push(b - a);

            } else if (token == "/") {
                pending.push(b / a);

            } else {
                cerr << "unrecognized operand: " << token << endl;
            }
        }
    }
    return pending.top();
}

int main() {
    string expression;
    while (input("Expression: ", expression)) {
        cout << calc(expression) << endl;
    }
}