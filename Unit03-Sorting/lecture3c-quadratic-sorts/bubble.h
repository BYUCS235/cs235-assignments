#pragma once

#include <vector>
using std::vector;

#include "handy.h" // PRINT macro
using handy::swap;

template <class T>
void sort(vector<T> &items)
{
    bool modified = true;
    while (modified)
    {
        modified = false;
        for (size_t i = 0; i < items.size() - 1; i++)
        {
            PRINT(items, i, -1, -1)

            if (items[i] > items[i + 1])
            {
                modified = true;
                swap(items[i], items[i + 1]);
                PRINT(items, i, i, i + 1)
            }
        }
    }
}
