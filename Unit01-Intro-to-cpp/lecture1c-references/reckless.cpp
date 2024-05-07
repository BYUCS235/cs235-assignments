#include <string>
using std::string;

#include <iostream>
using std::cout, std::cerr, std::endl;

#include <cstdlib>
using std::atoi;


void reckless_with_your_data(int& number, string& phrase) {
    for (int i = 0; i < number; i++) {
        cout << phrase << endl;
    }
}

int main(int argc, char** argv) {
    if (argc < 3) { cerr << "Needs count and 'text'" << endl; return 1; }

    int count = atoi(argv[1]);
    string text = argv[2];

    cout << "First time:" << endl;
    reckless_with_your_data(count, text);

    cout << "Second time:" << endl;
    reckless_with_your_data(count, text);
}