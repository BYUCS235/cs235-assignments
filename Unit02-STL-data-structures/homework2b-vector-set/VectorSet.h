#pragma once

template<class T>
class VectorSet {
public:
    bool contains(T item) const {
        // implement contains here

        // return true if item is in the set and false if not
    }

    bool insert(T item) {
        // implement insert here

        // return true if item is inserted and false if item is already in the
        // set
    }

    bool remove(T item) {
        // implement remove here

        // return true if item is removed and false if item wasn't in the set
    }

    int size() const {
        // implement size here

        // return the number of items in the set
    }

    bool empty() const {
        // implement empty here

        // return true if the set is empty and return false otherwise
    }

    void clear() {
        // implement clear here

        // remove all items from the set
    }
};
