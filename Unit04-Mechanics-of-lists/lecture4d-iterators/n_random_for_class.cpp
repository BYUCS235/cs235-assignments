#include <iostream>
using std::cout, std::endl;

class Random {
    size_t _n;
    
    public:
    Random(size_t n) : _n(n) {}

    class iterator {
        friend class Random;

        size_t _n;
        size_t _cur;

        iterator(size_t n, size_t cur) : _n(n), _cur(cur) {}

        public:
        bool operator==(const iterator& other) {
            return other._cur == _cur;
        }

        bool operator!=(const iterator& other) {
            return other._cur != _cur;
        }

        iterator& operator++() {
            _cur++;
            return *this;
        }

        int operator*() {
            return rand();
        }
    };

    iterator begin() {
        return iterator(_n, 0);
    }

    iterator end() {
        return iterator(_n, _n);
    }
};

int main() {
    for (auto num : Random(10)) {
        cout << num << endl;
    }
}