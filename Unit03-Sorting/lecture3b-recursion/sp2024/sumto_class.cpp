#include <iostream>
using std::cout, std::endl;

int sumto(int x) {
    if (x < 0) {
        return x + sumto(x+1);
    }
    else if (x == 0) {
        return 0;
    } else {
        return x + sumto(x-1);
    }
}

int main(int argc, char* argv[]) {
    cout << sumto(atoi(argv[1])) << endl;
}