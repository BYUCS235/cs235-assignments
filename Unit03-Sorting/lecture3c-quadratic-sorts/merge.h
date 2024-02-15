#pragma once

#include <vector>
using std::vector;

#include "handy.h" // PRINT macro
using handy::swap;

template <class T>
void merge(vector<T> const &left, vector<T> const &right, vector<T> &list)
{
    list.clear();
    size_t i = 0;
    size_t j = 0;

    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
        {
            list.push_back(left[i++]);
            PRINT(left, i - 1, -1, -1)
            PRINT(right, j, -1, -1)
        }
        else
        {
            list.push_back(right[j++]);
            PRINT(left, i, -1, -1)
            PRINT(right, j - 1, -1, -1)
        }
        PRINT(list, -1, list.size()-1, -1)
    }

    // Only one of these loops will actually run
    while (i < left.size())
    {
        list.push_back(left[i++]);
        PRINT(left, i - 1, -1, -1)
        PRINT(right, j, -1, -1)
        PRINT(list, -1, list.size()-1, -1)
    }
    while (j < right.size())
    {
        list.push_back(right[j++]);
        PRINT(left, i, -1, -1)
        PRINT(right, j - 1, -1, -1)
        PRINT(list, -1, list.size()-1, -1)
    }
}

template <class T>
void split(vector<T> const &items, vector<T> &left, vector<T> &right)
{
    left.clear();
    right.clear();
    size_t mid = items.size() / 2;
    for (size_t i = 0; i < mid; i++)
    {
        left.push_back(items[i]);
    }
    for (size_t i = mid; i < items.size(); i++)
    {
        right.push_back(items[i]);
    }
}

template <class T>
void sort(vector<T> &items)
{
    if (items.size() < 2) { return; }
    vector<T> left;
    vector<T> right;
    split(items, left, right);
    sort(left);
    sort(right);
    merge(left, right, items);
}
