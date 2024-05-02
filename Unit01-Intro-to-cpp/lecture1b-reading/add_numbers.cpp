#include <iostream>
using std::cout, std::endl;

#include <fstream>
using std::ifstream;

int main(int argc, char* argv[]) {
    ifstream file(argv[1]);
    int total(0);
    int token;
    while (file >> token) {
        total += token;
    }
    cout << "Total in " << argv[1] << " is " << total << endl;
    file.close();
}