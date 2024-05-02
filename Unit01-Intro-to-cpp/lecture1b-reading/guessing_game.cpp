#include <string>
using std::string, std::stoi;

#include <iostream>
using std::cout, std::cerr, std::cin, std::endl, std::getline;

#include <cstdlib> // rand, srand
#include <ctime>   // time

int main()
{
    srand(time(0));
    int secret = rand() % 100;
    cout << "Guess a number between 0 and 99." << endl;
    int guess = -1;

    while (guess != secret)
    {
        cout << "Guess: ";
        string response;
        getline(cin, response);
        guess = stoi(response);

        if (guess < secret)
        {
            cout << "Higher" << endl;
        }
        else if (guess > secret)
        {
            cout << "Lower" << endl;
        }
    }
    cout << "You got it!" << endl;
}