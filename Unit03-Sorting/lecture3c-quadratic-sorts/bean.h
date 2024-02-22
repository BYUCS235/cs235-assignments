#include <vector>
using std::vector;

#include <iostream>
using std::cout, std::endl;

#include <algorithm>
using std::swap;

#include "handy.h" // PRINT

template <class T>
void merge(vector<T> &items, size_t start_a, size_t end_a, size_t start_b, size_t end_b) {
    size_t a = start_a;
    size_t b = start_b;
    TRACK(start_a)
    TRACK(start_b)
    while (a < end_a && b < end_b) {
        TRACK(a)
        TRACK(items[a])
        TRACK(b)
        TRACK(items[b])
        // Compare a and b
        if (items[b] < items[a]) {
            // b belongs in a's spot
            swap(items[a], items[b]);
            PRINT(items, -1, a, b)

            // the item in slot a is now sorted
            a++;
            PRINT(items, a, -1, -1);
        
            // the item in slot b is now potentially out of place
            // if b > c, then we want to swap c down with a
            size_t c = b + 1;
            while (a < end_a && c < end_b && items[c] < items[b]) {
               if (items[c] < items[a]) {
                    swap(items[a], items[c]);
                    PRINT(items, b, a, c)
                    a++;
                    c++;
                }
            }
            
            // TODO Fix sort stability
            // merge(4a 4b 4c 4d 1 2 7 9)
            // results in 1 2 4c 4d 4a 4b 7 9 at this step of the code
            // Need to fix relative ordering in a..a_end and b..c
            
            if ((a == end_a || c > b + 1) && items[c] < items[c - 1]) {
                merge(items, b, c, c, end_b);
            }
        } else {
            // the item in a is now verified as sorted
            PRINT(items, a, -1, -1);
            a++;
        }
    }
}

template<class T>
void sort(vector<T> &items, size_t start, size_t end) {
    if (end - start < 2) { 
        return;
    }
    size_t mid = (end - start) / 2 + start;
    sort(items, start, mid);
    sort(items, mid, end);
    merge(items, start, mid, mid, end);
}

template<class T>
void sort(vector<T> &items) {
    sort(items, 0, items.size());
}
