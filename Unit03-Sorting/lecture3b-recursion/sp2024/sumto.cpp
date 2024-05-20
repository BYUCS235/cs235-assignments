#include <iostream>
using std::cout, std::endl;

int sumto(int x)
{
    cout << x << endl;

    if (x == 1) {
        return 1;
    }

    return x + sumto(x - 1);
}

int main(int argc, char *argv[])
{
    cout << sumto(atoi(argv[1])) << endl;
}