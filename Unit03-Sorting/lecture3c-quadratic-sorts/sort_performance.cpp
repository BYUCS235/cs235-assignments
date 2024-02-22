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

#elif SORT == 6 // bean
#include "bean.h"

#elif SORT == 7 // std::sort
#include <algorithm>
template <class T>
void sort(vector<T> &items)
{
    std::sort(items.begin(), items.end());
}

#else

template <class T>
void sort(vector<T> &items)
{
    std::cerr << "'sort' not defined! Be sure to compile with -DSORT 1|2|3|4|5" << endl;
}
#endif

#ifndef DEFAULT_N
#define DEFAULT_N 80000
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

template <class T>
struct SideCar
{
    T value;
    size_t pos;
    SideCar(T const &value, size_t pos) : value(value), pos(pos) {}
    bool operator>(const SideCar &other) const
    {
        return (value > other.value);
    }
    bool operator<(const SideCar &other) const
    {
        return (value < other.value);
    }
};

template <class T>
bool certify_stable(vector<SideCar<T>> const &items)
{
    if (items.empty())
    {
        return true;
    }
    size_t pos = 1;
    while (pos < items.size())
    {
        if (items[pos].value == items[pos - 1].value && items[pos].pos > items[pos - 1].pos)
        {
            return false;
        }
        pos++;
    }
    return true;
}

int main(int argc, char *argv[])
{
    int N;
    if (argc == 2)
    {
        N = atoi(argv[1]);
    }
    else
    {
        N = DEFAULT_N;
    }

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
    if (!certify(numbers))
    {
        cerr << "Not sorted!" << endl;
        return 1;
    }
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
    if (!certify(numbers))
    {
        cerr << "Not sorted!" << endl;
        return 1;
    }
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
    if (!certify(numbers))
    {
        cerr << "Not sorted!" << endl;
        return 1;
    }
    cout << "...took " << timer.milliseconds() << " ms" << endl;

    cout << endl;
    cout << "Stable sort?" << endl;
    vector<SideCar<int>> stable_numbers;
    for (size_t i = 0; i < N; i++)
    {
        stable_numbers.push_back(SideCar(rand() % 20, i));
    }
    timer.start();
    sort(stable_numbers);
    timer.stop();
    cout << "...took " << timer.milliseconds() << " ms" << endl;
    if (!certify_stable(stable_numbers))
    {
        cerr << "Not a stable sort!" << endl;
    }
    else
    {
        cout << "Stable!" << endl;
    }
}