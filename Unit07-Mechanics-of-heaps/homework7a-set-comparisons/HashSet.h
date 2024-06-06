#pragma once

template<class T>
class HashSet {
public:
    HashSet() {}

    ~HashSet() {}

    bool insert(T item) {
        // implement insert here
        // return true if item was inserted, false if item was already in the set
    }

    bool remove(T item) {
        // implement remove here
        // return true if item was removed, false if item wasn't in the set
    }

    bool contains(T item) const {
        // implement contains here
        // return true if item is in the set, false otherwise
    }

    void clear() {
        // implement clear here
        // remove all elements from the set
    }

    int size() const {
        // implement size here
        // return the number of elements in the set
    }
};
