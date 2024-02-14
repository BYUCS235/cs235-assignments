#include <string>
#include <vector>
#include <iostream>

using namespace std;

template<class C>
void print(C& stuff) {
    for (auto thing : stuff) {
        cout << thing << " ";
    }
    cout << endl;
}


template<class T>
void insertion_sort(vector<T>& stuff) {
    for (int i = 1; i < stuff.size(); i++) {
        cout << endl << "i is " << i << endl;
        print(stuff);

        // Grab item i and save it
        T item = stuff[i];

        // Shift the sort stuff to the right until I find where item belongs
        int j = i;
        while (j > 0 && item < stuff[j-1]) {
            stuff[j] = stuff[j-1];
            print(stuff);
            j--;
        }

        // Insert the item in it's sorted position
        cout << "item " << item << " belongs in position " << j << endl;
        stuff[j] = item;

        print(stuff);
    }
}

int main(int argc, char* argv[]) {
    vector<string> stuff;
    for (int i = 1; i < argc; i++) {
        stuff.push_back(argv[i]);
    }
    insertion_sort(stuff);
    cout << endl;
    for (auto word : stuff) {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}