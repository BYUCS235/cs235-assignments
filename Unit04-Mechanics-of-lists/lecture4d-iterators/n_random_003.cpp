#include <iostream>
using std::cout, std::endl;

class Random {
    int _n;
    
    public:
    Random(int n) : _n(n) {}

    class iterator {
        int _current;
        int _n;
        int _count;

        public:
        iterator(int n) : _n(n), _count(0) {}

        bool operator !=(iterator const& other) {
            return _count < _n;
        }

        iterator& operator++() {
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