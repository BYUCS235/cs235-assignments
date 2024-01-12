#include <iostream>
using std::cout, std::endl, std::cin;

int main() {
    int a;
    int b;

    cout << "Enter a single number: ";
    cin >> a;  // a = input('number: ')
    cout << "Enter another number: ";
    cin >> b;
    cout << "The sum of " << a << " + " << b << " is " << a + b << endl;    
}