#include <string>
#include <vector>
#include <iostream>

using namespace std;

template<class T>
void selection_sort(vector<T>& stuff) {
    for (int i = 0; i < stuff.size()-1; i++) { // Move the partition from 0 to n-2
        cout << endl << "i is " << i << endl;
        for (T thing : stuff) {
            cout << thing << " ";
        }
        cout << endl;

        // Find the min of the unsorted partition
        int min = i;
        for (int j = i; j < stuff.size(); j++) { // Search the unsorted partition for the min
            if (stuff[j] < stuff[min]) {
                min = j;
            }
        }
        cout << "swapping " << i << " with " << min << endl;

        // Swap i and min
        T tmp = stuff[i];
        stuff[i] = stuff[min];
        stuff[min] = tmp;

        for (T thing : stuff) {
            cout << thing << " ";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {
    vector<string> stuff;
    for (int i = 1; i < argc; i++) {
        stuff.push_back(argv[i]);
    }
    selection_sort(stuff);
    cout << endl;
    for (auto word : stuff) {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}