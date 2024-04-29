#include <cstdlib>  // rand, srand, size_t
#include <iostream>
using std::cout, std::endl;

int main(int argc, char *argv[])
{
    size_t val = atoi(argv[1]);
    size_t threshold = atoi(argv[2]);
    cout << "val is " << val << endl;
    while (val > threshold)
    {
        cout << val << " is to big." << endl;
        int divisor = rand() % 10;
        cout << "Let's divide it by " << divisor << endl;
        val = val / divisor;
        cout << "val is now " << val << endl;
    }
}