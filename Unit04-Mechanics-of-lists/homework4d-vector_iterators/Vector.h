#pragma once

#include <iostream>
#include <string>

template<class T>
class Vector {
public:
    class Iterator {
    public:
        T& operator*() {
            // implement operator* here
        }

        Iterator& operator++() {
            // implement operator++ here
        }

        bool operator==(const Iterator& other) const {
            // implement operator== here
        }

        bool operator!=(const Iterator& other) const {
            // implement operator!= here
        }
    };

    Iterator begin() {
        // implement begin here
    }

    Iterator end() {
        // implement end here
    }

    // paste in your methods from the vector assignment

private:
    // paste in your data members from the vector assignment
};
