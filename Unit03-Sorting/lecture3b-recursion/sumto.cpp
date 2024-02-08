#include <iostream>
using namespace std;

int sumto(int x) {
    cout << "x = " << x << endl;
    if (x < 1) {
        throw std::invalid_argument("x must be >= 1");
    }
    if (x == 1) return 1;
    return x + sumto(x-1);
}

int main(int argc, char* argv[]) {
    cout << sumto(atoi(argv[1])) << endl;
    return 0;
}
