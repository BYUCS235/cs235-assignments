//
// Created by Gordon Bean on 2/9/22.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template<class C>
void print(C const& stuff, string sep = " ") {
    for (auto const& thing : stuff) {
        cout << thing << sep;
    }
    if (sep != "\n") {
        cout << endl;
    }
}

/*
 * Selection Sort
 */
template<class T>
void selection_sort(vector<T>& stuff) {
    for (int i = 0; i < stuff.size()-1; i++) { // Move the partition from 0 to n-2
#ifdef VERBOSE
        cout << endl << "i is " << i << endl;
        print(stuff);
#endif

        // Find the min of the unsorted partition
        int min = i;
        for (int j = i; j < stuff.size(); j++) { // Search the unsorted partition for the min
            if (stuff[j] < stuff[min]) {
                min = j;
            }
        }
#ifdef VERBOSE
        cout << "swapping " << i << " with " << min << endl;
#endif
        // Swap i and min
        T tmp = stuff[i];
        stuff[i] = stuff[min];
        stuff[min] = tmp;

#ifdef VERBOSE
        print(stuff);
#endif
    }
}

/*
 * Insertion Sort
 */
template<class T>
void insertion_sort(vector<T>& stuff) {
    for (int i = 1; i < stuff.size(); i++) {
#ifdef VERBOSE
        cout << endl << "i is " << i << endl;
        print(stuff);
#endif
        // Grab item i and save it
        T item = stuff[i];

        // Shift the sort stuff to the right until I find where item belongs
        int j = i;
        while (j > 0 && item < stuff[j-1]) {
            stuff[j] = stuff[j-1];
#ifdef VERBOSE
            print(stuff);
#endif
            j--;
        }

        // Insert the item in it's sorted position
        stuff[j] = item;
#ifdef VERBOSE
        cout << "item " << item << " belongs in position " << j << endl;
        print(stuff);
#endif
    }
}

/*
 * Merge Sort
 */
template<class T>
void merge(vector<T> const& A, vector<T> const& B, vector<T>& AB) {
    // Iterate through both lists,
    // adding the minimum between each lists' items
    // to the combined list
    auto a_it = A.begin();
    auto b_it = B.begin();
    while (a_it != A.end() && b_it != B.end()) {
        auto& min_it = (*a_it < *b_it) ? a_it : b_it;
        AB.push_back(*min_it);
        min_it++;
    }

    // Which list still has unadded items?
    auto extra_it = (a_it != A.end()) ? a_it : b_it;
    const auto end_it = (a_it != A.end()) ? A.end() : B.end();
    while (extra_it != end_it) {
        AB.push_back(*extra_it);
        extra_it++;
    }

#ifdef VERBOSE
    cout << "merge:" << endl;
    print(A);
    print(B);
    print(AB);
    cout << endl;
#endif
}

template<class T>
void split(vector<T> const& source, vector<T>& left, vector<T>& right) {
    int split = source.size() / 2;
    for (int i = 0; i < split; i++) {
        left.push_back(source.at(i));
    }
    for (int i = split; i < source.size(); i++) {
        right.push_back(source.at(i));
    }
#ifdef VERBOSE
    cout << "split:" << endl;
    print(source);
    print(left);
    print(right);
    cout << endl;
#endif
}

template<class T>
void merge_sort(vector<T>& things) {

    if (things.size() == 1) {
        return;
    }

    vector<T> left;
    vector<T> right;

    split(things, left, right);

    merge_sort(left);
    merge_sort(right);

    things.clear();
    merge(left, right, things);
}

int main(int argc, char* argv[]) {
    // argv[1] is the algorithm
    if (argc < 1) {
        throw invalid_argument("Please provide an algorithm");
    }
    string algorithm = argv[1];

    // if argc == 2, read from stdin
    // otherwise use argv[2:]
    vector<string> stuff;
    if (argc == 2) {
        string word;
        while (cin >> word) {
            stuff.push_back(word);
        }
    } else {
        for (int i = 2; i < argc; i++) {
            stuff.push_back(argv[i]);
        }
    }

    if (algorithm == "selection") {
        selection_sort(stuff);

    } else if (algorithm == "insertion") {
        insertion_sort(stuff);

    } else if (algorithm == "merge") {
        merge_sort(stuff);

    } else if (algorithm == "quick") {
        // Use built-in quicksort
        sort(stuff.begin(), stuff.end());

    } else if (algorithm == "nothing") {
        // Leave the input as-is

    } else {
        cout << "Unrecognized algorithm: " << algorithm << endl;
        return 1;
    }

    print(stuff, "\n");
    return 0;
}

