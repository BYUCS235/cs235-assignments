#include <iostream>
using std::cout, std::endl;

class Random {
    size_t _how_many;

    public:

    Random(size_t how_many) : _how_many(how_many) {}

    class iterator {
        friend class Random;

        size_t current;

        iterator(size_t current) : current(current) { }

        public:

        bool operator !=(iterator const& end) {
            // Should I keep going?
            return current != end.current;
        }

        // Define ++ to move from the current position to the next one
        iterator& operator++() {
            current++;
            return *this;
        }

        // Define * to retrieve the value at the current position
        int operator*() {
            return rand();
        }
    };

    iterator begin() {
        return iterator(0);
    }
    
    iterator end() {
        return iterator(_how_many);
    }
};

int main() {
    for (auto num : Random(10)) {
        cout << num << endl;
    }
}