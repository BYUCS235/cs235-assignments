#include <iostream>
using std::cin;  // inherits from istream
using std::cout;
using std::endl;
using std::getline;
using std::istream;

#include <fstream>
using std::ifstream;  // also inherits from istream

#include <string>
using std::string;


/**
 * Add bullets to each line
 */
void bullets(istream& ins) {
    string line;
    while (getline(ins, line)) {
        cout << "* " << line << endl;
    }
}

int main(int argc, char** argv) {
    // If filename provided, open it
    // Otherwise use STDIN

    if (argc == 2) {
        // Use file
        cout << "using file stream" << endl;
        ifstream input(argv[1]);
        if (input.is_open()) {
            bullets(input);
            input.close();
        } else {
            std::cerr << "unable to open " << argv[1] << endl;
            return 1;
        }

    } else {
        // Use STDIN
        cout << "using cin" << endl;
        bullets(cin);
    }

    return 0;
}