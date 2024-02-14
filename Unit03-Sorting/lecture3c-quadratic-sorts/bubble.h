#pragma once

#include <vector>
using std::vector;

#include <algorithm>
using std::swap;

template <class T>
void sort(vector<T> &items)
{
    bool modified = true;
    while (modified)
    {
        modified = false;
        for (size_t i = 0; i < items.size() - 1; i++)
        {
            if (items[i] > items[i + 1])
            {
                modified = true;
                swap(items[i], items[i + 1]);
            }
        }
    }
}
