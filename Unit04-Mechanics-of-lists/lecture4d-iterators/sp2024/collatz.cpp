#include <iostream>
using std::cout, std::endl;


class Collatz {
    int start;

    public:
    Collatz(int start) : start(start) {}

    class iterator {
        friend class Collatz;
        int _current;

        iterator(int n) : _current(n) {}
        public:

        bool operator !=(iterator const& end) {
            return _current != end._current;
        }

        iterator& operator++() {
            if (_current & 1) {
                _current = _current * 3 + 1;
            } else {
                _current = _current >> 1;
            }
            return *this;
        }

        int operator*() {
            return _current;
        }
    };

    iterator begin() {
        return iterator(start);
    }
    iterator end() {
        return iterator(1);  
    }
};

int main(int argc, char* argv[]) {
    for (int val : Collatz(atoi(argv[1]))) {
        cout << val << endl;
    }
}

/* Python
def collatz(start):
    while start > 1:
        yield start
        if start & 1:
            start = start * 3 + 1
        else:
            start = start >> 1
*/