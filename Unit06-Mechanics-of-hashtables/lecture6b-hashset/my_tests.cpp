#include "HashSet_003.h"

#include <iostream>
using std::cout, std::endl;

#include <cassert>

int main() {
    HashSet<int> set;
    set.clear();

    for (int i = 0; i < 8; i++) {
        set.insert(i);
    }

    assert(set.size() == 8);

    cout << std::boolalpha;
    cout << set << endl;

    cout << set.insert(7) << endl;
    cout << set.insert(15) << endl;

    cout << set << endl;

    cout << set.remove(7) << endl;
    cout << set.remove(6) << endl;

    assert(set.size() == 7);

    cout << set << endl;

    set.clear();

}