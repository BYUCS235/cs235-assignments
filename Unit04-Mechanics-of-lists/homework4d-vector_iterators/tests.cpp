#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

#include "Vector.h"

// --------- HELPER FUNCTIONS --------- 

template<class T>
void print_vector(Vector<T>& vector) {
    std::cout << "vector =";
    for (int i = 0; i < vector.size(); i++) {
        std::cout << ' ' << vector[i];
    }
    std::cout << std::endl;
}

// --------- END HELPER FUNCTIONS --------- 

// Iterates over a vector of integers using for-each syntax, adding 1 to each
// integer
void test1() {
    std::cout << "--- Test 1 output ---\n" << std::endl;

    Vector<int> vector;

    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(3);
    vector.push_back(4);
    vector.push_back(5);
    print_vector(vector);

    std::cout << std::endl;
    std::cout << "using for-each syntax to increment each element by 1..." << std::endl;
    for (int& item : vector) {
        item += 1;
    }
    print_vector(vector);
}

// Iterates over a vector of strings using for-each syntax, uppercasing each
// string
void test2() {
    std::cout << "--- Test 2 output ---\n" << std::endl;

    Vector<std::string> vector;

    vector.push_back("waterfall");
    vector.push_back("enigma");
    vector.push_back("guitar");
    vector.push_back("zebra");
    vector.push_back("luminous");
    print_vector(vector);

    std::cout << std::endl;
    std::cout << "using for-each syntax to make each element uppercase..." << std::endl;
    for (std::string& item : vector) {
        std::transform(item.begin(), item.end(), item.begin(), [](unsigned char c) { return std::toupper(c); });
    }
    print_vector(vector);
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        std::cerr << "You must specify which tests you would like to run (your options are 1, 2, and\n"
            "all). You can specify several options by separating them by spaces."
            << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (std::strcmp(argv[i], "1") == 0) {
            test1();
        } else if (std::strcmp(argv[i], "2") == 0) {
            test2();
        } else if (std::strcmp(argv[i], "all") == 0) {
            test1();
            std::cout << std::endl;

            test2();
        } else {
            std::cerr << argv[i] << " isn't a valid option (1, 2, or all)" << std::endl;
        }

        if (i + 1 != argc) {
            std::cout << std::endl;
        }
    }

    return 0;
}
