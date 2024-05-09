// :)
#pragma once

#include <vector>
using std::vector;

#include <iostream>
using std::cout, std::endl;

template<class T>
class NoisyVector {
    private:
    vector<T> _data;

    size_t _pushes;
    size_t _pops;
    size_t _sizes;
    size_t _brackets;

    public:
    NoisyVector() : _data(), _pushes(0), _pops(0), _sizes(0), _brackets(0) { }

    size_t size() { 
        cout << "size called " << ++_sizes << " times" << endl;
        return _data.size(); 
    }

    void push_back(T const& item) {
        cout << "push_back called " << ++_pushes << " times" << endl;
        _data.push_back(item);
    }

    void pop_back() {
        cout << "pop_back called " << ++_pops << " times" << endl;
        _data.pop_back();
    }

    T& operator[](size_t pos) {
        cout << "brackets called " << ++_brackets << " times" << endl;
        return _data[pos];
    }
};
