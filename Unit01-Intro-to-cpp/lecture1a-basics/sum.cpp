#include <iostream>
using std::cout, std::endl;

int main(int argc, char* argv[]) {
    int total = 0;
    for (int i = 1; i < argc; i++) {
        total += atoi(argv[i]);
    }
    
    cout << total << endl;
}