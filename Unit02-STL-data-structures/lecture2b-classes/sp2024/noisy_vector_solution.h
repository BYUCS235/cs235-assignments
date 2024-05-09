#pragma once

#include <vector>
#include <string>
#include <iostream>

template <class T>
class NoisyVector {
    std::vector<T> items;    
    size_t push_count;
    size_t pop_count;
    size_t size_count;
    size_t index_count;

    void announce(std::string const& method, size_t const how_many) {
        std::cout << "(" << method << " called " << how_many << " time" << ((how_many > 1) ? "s" : "") << ")" << endl;
    }

    public:
    NoisyVector() : push_count(0), pop_count(0), size_count(0), index_count(0) {}

    void push_back(T item) {
        announce("push_back", ++push_count);
        items.push_back(item);
    }

    void pop_back() {
        announce("pop_back", ++pop_count);
        items.pop_back();
    }

    size_t size() {
        announce("size", ++size_count);
        return items.size();
    }

    T& operator[](size_t position) {
        announce("[]", ++index_count);
        return items[position];
        // This lets us do something like:
        // NoisyVector<int> nv;
        // nv.push_back(1);
        // nv[0] = 7;
    }
};