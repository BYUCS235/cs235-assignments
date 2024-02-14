#include <vector>
using std::vector;

#include <iostream>
using std::cout, std::cerr, std::endl;

#include "handy.h"
using handy::Timer;

#include <string>
using std::string;

#include <stdlib.h> // srand, rand

#if SORT == 1 // bubble
#include "bubble.h"

#elif SORT == 2 // selection
#include "selection.h"

#elif SORT == 3 // insertion
#include "insertion.h"

#elif SORT == 4 // merge
#include "merge.h"

#elif SORT == 5 // quick
#include "quick.h"

#else

template <class T>
void sort(vector<T> &items)
{
    std::cerr << "'sort' not defined! Be sure to compile with -DSORT 1|2|3|4|5" << endl;
}
#endif

#ifndef N
#define N 20000 
#endif

template <class T>
bool certify(vector<T> const &items)
{
    for (size_t i = 0; i < items.size() - 1; i++)
    {
        if (items[i] > items[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    srand(0);
    vector<int> numbers;
    Timer timer;
    cout << "Sorting a list of " << N << " integers" << endl;
    cout << endl;

    cout << "Already sorted..." << endl;
    numbers.clear();
    for (int i = 0; i < N; i++)
    {
        numbers.push_back(i);
    }
    timer.start();
    sort(numbers);
    timer.stop();
    if (!certify(numbers)) { cerr << "Not sorted!" << endl; return 1; }
    cout << "...took " << timer.milliseconds() << " ms" << endl;

    cout << endl;
    cout << "Reverse sorted..." << endl;
    numbers.clear();
    for (int i = N; i > 0; i--)
    {
        numbers.push_back(i);
    }
    timer.start();
    sort(numbers);
    timer.stop();
    if (!certify(numbers)) { cerr << "Not sorted!" << endl; return 1; }
    cout << "...took " << timer.milliseconds() << " ms" << endl;

    cout << endl;
    cout << "Random numbers..." << endl;
    numbers.clear();
    for (int i = 0; i < N; i++)
    {
        numbers.push_back(rand());
    }
    timer.start();
    sort(numbers);
    timer.stop();
    if (!certify(numbers)) { cerr << "Not sorted!" << endl; return 1; }
    cout << "...took " << timer.milliseconds() << " ms" << endl;
}