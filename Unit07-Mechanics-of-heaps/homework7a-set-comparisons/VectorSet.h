#pragma once

template<class T>
class VectorSet {
public:
    bool contains(T item) const {
        return false;
    }

    bool insert(T item) {
        return false;
    }

    bool remove(T item) {
        return false;
    }

    int size() const {
        return 0;
    }

    bool empty() const {
        return true;
    }

    void clear() {

    }
};
