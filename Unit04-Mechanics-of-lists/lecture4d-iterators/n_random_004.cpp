#include <iostream>
using std::cout, std::endl;

class Random {
    int _n;

    public:
    Random(int n) : _n(n) {}

    class iterator {
        friend class Random;

        int _current;
        int _how_many;
        int _count;

        iterator(int n) : _current(rand()), _how_many(n), _count(0) {}

        public:
        bool operator !=(iterator const& other /*ignored*/ ) {
            // should I keep going?
            return _count < _how_many;
        }

        iterator& operator++() {
            // move to next value
            _current = rand();
            _count++;
            return *this;
        }

        int operator*() {
            return _current;
        }
    };

    iterator begin() {
        return iterator(_n);
    }

    iterator end() {
        return iterator(-1);  // ignored
    }
};

int main() {
    for (auto num : Random(10)) {
        cout << num << endl;
    }
}