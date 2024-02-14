#pragma once

#include <vector>
using std::vector;

#include <algorithm>
using std::swap;

template <class T>
void sort(vector<T> &stuff)
{
    // Move the partition from 0 to n-2
    for (int i = 0; i < stuff.size() - 1; i++)
    { 
        // Find the min of the unsorted partition
        int min = i;
        for (int j = i; j < stuff.size(); j++)
        { 
            if (stuff[j] < stuff[min])
            {
                min = j;
            }
        }
        // Swap i and min
        swap(stuff[i], stuff[min]);
    }
}