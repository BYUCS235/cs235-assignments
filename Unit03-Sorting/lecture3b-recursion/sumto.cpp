#include <iostream>
using namespace std;

// int sumto(int x);

int sumto(int x) {
    cout << x << endl;
    if (x <= 0) { return 0; }
    return x + sumto(x-1);
}

int main(int argc, char* argv[]) {
    cout << sumto(atoi(argv[1])) << endl;
}