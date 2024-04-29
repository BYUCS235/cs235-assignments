#include <iostream>
using std::cout, std::cerr, std::endl;

#include "math_stuff.h"
using mathy::subtract;

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        cerr << "You need to provide two arguments" << endl;
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    cout << a << " - " << b << " = " << subtract(a, b) << endl;
}