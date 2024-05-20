#include <iostream>
using std::cout, std::endl;

int sumto(int x) {
    return x + sumto(x-1);
}


int main(int argc, char* argv[]) {
    cout << sumto(atoi(argv[1])) << endl;
}