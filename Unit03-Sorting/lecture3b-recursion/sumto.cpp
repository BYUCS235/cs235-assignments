#include <iostream>
using namespace std;

int sumto(int x) {
    if (x == 0) return 0;
    return x + sumto(x-1);
}

int main(int argc, char* argv[]) {
    cout << sumto(atoi(argv[1])) << endl;
    return 0;
}
