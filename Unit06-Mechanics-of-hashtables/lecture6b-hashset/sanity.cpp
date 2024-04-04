#include "HashSet_004.h"

#include <cassert> // assert
int main() {
    HashSet<int> set;
    assert(set.size() == 0);
    assert(!set.contains(0));
    assert(!set.contains(6));

    assert(set.insert(7));
    assert(!set.insert(7));
    assert(set.size() == 1);

    assert(set.insert(15));
    assert(set.size() == 2);

    cout << set << endl;

    for (int i = 0; i < 8; i++) {
        set.insert(i);
    }
    cout << set << endl;

    assert(set.remove(6));
    assert(!set.remove(6));
    assert(set.size() == 8);

    cout << set << endl;
    set.clear();
    assert(set.size() == 0);

    assert(set.insert(8));
}