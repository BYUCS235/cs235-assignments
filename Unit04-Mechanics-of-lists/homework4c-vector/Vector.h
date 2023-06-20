#pragma once

#include <iostream>
#include <string>

template<class T>
class Vector {
public:
    Vector() {}

    ~Vector() {}

    void push_back(T item) {
        // implement push_back here
    }

    void insert(T item, int position) {
        // implement insert here
    }

    void remove(int position) {
        // implement remove here
    }

    T& operator[](int index) {
        // implement operator[] here
    }

    int size() const {
        // implement size here
    }

    void clear() {
        // implement clear here
    }
};
