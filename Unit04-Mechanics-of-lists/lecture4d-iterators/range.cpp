#include <iostream>
using std::cout, std::endl;

class Range {
    int lower;
    int upper;
    int step;
    public:
    Range(int upper) : Range(0, upper) {}
    Range(int lower, int upper): Range(lower, upper, 1) {}
    Range(int lower, int upper, int step) : lower(lower), upper(upper), step(step) {}

    class iterator {
        int current;
        int step;
        public:
        iterator(int start, int step) : current(start), step(step) {}

        bool operator !=(iterator const& end) {
            // Should I keep going?
            return current < end.current;
        }

        // Define ++ to move from the current position to the next one
        iterator& operator++() {
            current += step;
            return *this;
        }

        // Define * to retrieve the value at the current position
        int operator*() {
            return current;
        }
    };

    iterator begin() const {
        return iterator(lower, step);
    }

    iterator end() const {
        return iterator(upper, 0);
    }
};

int main() {
    for (auto i : Range(10)) {
        cout << i << " ";
    }
    cout << endl;

    for (int i : Range(3, 22, 3)) {
        cout << i << " ";
    }
    cout << endl;
}