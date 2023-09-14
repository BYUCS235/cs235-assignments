#include <iostream>
using std::cout, std::endl;

/*
 should have two args: a, b
 multiply them together and print the result
*/
int main(int argc, char *argv[])
{
    // For demonstration purposes
    cout << "You gave me " << argc - 1 << " arguments" << endl;
    if (argc < 3) {
        std::cerr << "You must give at least 2 arguments" << endl;
        return 1;
    }

    // Real work
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int product = a * b;

    cout << a << " * " << b << " = " << product << endl;
    
}