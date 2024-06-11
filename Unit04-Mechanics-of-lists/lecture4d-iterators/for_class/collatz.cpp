#include <iostream>
using std::cout, std::endl;


class Collatz {
    
};

int main(int argc, char* argv[]) {
    for (int val : Collatz(atoi(argv[1]))) {
        cout << val << endl;
    }
}

/* Python
def collatz(start):
    while start > 1:
        yield start
        if start & 1:
            start = start * 3 + 1
        else:
            start = start >> 1
*/