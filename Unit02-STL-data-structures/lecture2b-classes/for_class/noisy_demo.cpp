#include <string>
using std::string;

#include <iostream>
using std::cout, std::endl, std::ostream;

#include "noisy_vector_solution.h"
// #include "noisy_vector.h"

// #define DEBUG
#include "../../../lib/debug.h"

template <class T>
ostream& operator<<(ostream &out, NoisyVector<T> & vec) {
    TRACE for (size_t i = 0; i < vec.size(); i++) {
        TRACE out << vec[i] << " ";
    }
    return out;
}

int main() {
    NoisyVector<string> words;

    TRACE words.push_back("walrus");
    TRACE words.push_back("stereo");
    TRACE words.push_back("banana");

    TRACE cout << "size: " << words.size() << endl;
    TRACE cout << words << endl;

    TRACE words.pop_back();
    TRACE words.pop_back();
    TRACE words.push_back("carpet");
    TRACE words[0] = "capybara";

    TRACE cout << "size: " << words.size() << endl;
    TRACE cout << words << endl;
}