#include <cstdlib>
using std::atoi;

#include <iostream>
using std::cout;
using std::endl;

#include "where.h"

void swap(int &first, int &second)
// void swap(int first, int second)
{
    WHERE(first);
    WHERE(second);
    cout << "first: " << first << endl;
    cout << "second: " << second << endl;
    
    cout << "swap first and second" << endl;
    cout << "i.e. swap data at " << &first << " and " << &second << endl;
    // The & operator gets the location of the variable

    int tmp = first;
    first = second;
    second = tmp;
    
    cout << "first: " << first << endl;
    cout << "second: " << second << endl;
}

int main(int argc, char **argv)
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    WHERE(a);
    WHERE(b);

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    swap(a, b);

    WHERE(a);
    WHERE(b);
    
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
}