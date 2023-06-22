#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string>

#include "Vector.h"

// --------- HELPER FUNCTIONS --------- 

template<class T>
void noisy_push_back(Vector<T>& vector, T item) {
    vector.push_back(item);
    std::cout << "vector.push_back(" << item << ')' << std::endl;
}

template<class T>
void noisy_insert(Vector<T>& vector, T item, int position) {
    try {
        vector.insert(item, position);
        std::cout << "vector.insert(" << item << ", " << position << ')' << std::endl;
    } catch (std::out_of_range& e) {
        std::cout << "vector.insert(" << item << ", " << position << ") threw an out_of_range exception" << std::endl;
    } catch (std::exception& e) {
        std::cout << "vector.insert(" << item << ", " << position << ") threw an exception: " << e.what() << std::endl;
    }
}

template<class T>
void noisy_remove(Vector<T>& vector, int position) {
    try {
        vector.remove(position);
        std::cout << "vector.remove(" << position << ')' << std::endl;
    } catch (std::out_of_range& e) {
        std::cout << "vector.remove(" << position << ") threw an out_of_range exception" << std::endl;
    } catch (std::exception& e) {
        std::cout << "vector.remove(" << position << ") threw an exception: " << e.what() << std::endl;
    }
}

template<class T>
void noisy_op_brackets_read(Vector<T>& vector, int index) {
    try {
        const T& item = vector[index];
        std::cout << "vector[" << index << "] = " << item << std::endl;
    } catch (std::out_of_range& e) {
        std::cout << "vector[" << index << "] threw an out_of_range exception" << std::endl;
    } catch (std::exception& e) {
        std::cout << "vector[" << index << "] threw an exception: " << e.what() << std::endl;
    }
}

template<class T>
void noisy_op_brackets_write(Vector<T>& vector, T item, int index) {
    try {
        vector[index] = item;
        std::cout << "vector[" << index << "] <- " << item << std::endl;
    } catch (std::out_of_range& e) {
        std::cout << "vector[" << index << "] threw an out_of_range exception" << std::endl;
    } catch (std::exception& e) {
        std::cout << "vector[" << index << "] threw an exception: " << e.what() << std::endl;
    }
}

template<class T>
void noisy_size(const Vector<T>& vector) {
    std::cout << "vector.size() = " << vector.size() << std::endl;
}

template<class T>
void noisy_clear(Vector<T>& vector) {
    vector.clear();
    std::cout << "vector.clear()" << std::endl;
}

template<class T>
void print_vector(Vector<T>& vector) {
    std::cout << "vector =";
    for (int i = 0; i < vector.size(); i++) {
        std::cout << ' ' << vector[i];
    }
    std::cout << std::endl;
}

// --------- END HELPER FUNCTIONS --------- 

// NOTE: all tests will require operator[] and size to be implemented (so that
// they can print the vector)

// Checks that push_back works
void test1() {
    std::cout << "--- Test 1 output ---\n" << std::endl;

    Vector<std::string> vector;

    noisy_push_back<std::string>(vector, "wonder");
    noisy_push_back<std::string>(vector, "yak");
    print_vector(vector);

    std::cout << std::endl;
    noisy_push_back<std::string>(vector, "bookshelf");
    noisy_push_back<std::string>(vector, "euphoria");
    print_vector(vector);

    std::cout << std::endl;
    noisy_push_back<std::string>(vector, "optimism");
    noisy_push_back<std::string>(vector, "cozy");
    print_vector(vector);
}

// Checks that insert works
void test2() {
    std::cout << "--- Test 2 output ---\n" << std::endl;

    Vector<int> vector;

    noisy_insert(vector, 5, 1);
    noisy_insert(vector, 7, 0);
    noisy_insert(vector, 6, 0);
    noisy_insert(vector, 4, 2);
    print_vector(vector);

    std::cout << std::endl;
    noisy_insert(vector, 12, 1);
    noisy_insert(vector, 1, 3);
    print_vector(vector);

    std::cout << std::endl;
    noisy_insert(vector, 7, 0);
    noisy_insert(vector, 5, 0);
    noisy_insert(vector, 19, 7);
    noisy_insert(vector, 5, 9);
    print_vector(vector);
}

// Checks that operator[] works for writing into the vector
void test3() {
    std::cout << "--- Test 3 output ---\n" << std::endl;

    Vector<std::string> vector;

    noisy_op_brackets_write<std::string>(vector, "seahorse", 0);
    noisy_push_back<std::string>(vector, "ice");
    noisy_push_back<std::string>(vector, "eggplant");
    noisy_push_back<std::string>(vector, "guitar");
    noisy_push_back<std::string>(vector, "narwhal");
    print_vector(vector);

    std::cout << std::endl;
    noisy_op_brackets_write<std::string>(vector, "jellyfish", 0);
    noisy_op_brackets_write<std::string>(vector, "zucchini", 1);
    noisy_op_brackets_write<std::string>(vector, "peace", 2);
    noisy_op_brackets_write<std::string>(vector, "serenity", 3);
    noisy_op_brackets_write<std::string>(vector, "whimsical", 4);

    print_vector(vector);
}

// Checks that remove works
void test4() {
    std::cout << "--- Test 4 output ---\n" << std::endl;

    Vector<int> vector;

    noisy_remove(vector, 0);
    noisy_push_back(vector, 19);
    noisy_push_back(vector, 1);
    noisy_push_back(vector, 7);
    noisy_push_back(vector, 12);
    noisy_push_back(vector, 2);
    print_vector(vector);

    std::cout << std::endl;
    noisy_remove(vector, 0);
    print_vector(vector);

    std::cout << std::endl;
    noisy_remove(vector, 3);
    print_vector(vector);

    std::cout << std::endl;
    noisy_remove(vector, 1);
    print_vector(vector);

    std::cout << std::endl;
    noisy_remove(vector, 0);
    noisy_remove(vector, 0);
    print_vector(vector);
}

// Checks that size and clear work
void test5() {
    std::cout << "--- Test 5 output ---\n" << std::endl;

    Vector<int> vector;

    noisy_size(vector);
    noisy_push_back(vector, 0);
    noisy_size(vector);
    noisy_insert(vector, 0, 0);
    noisy_size(vector);
    noisy_remove(vector, 0);
    noisy_size(vector);

    std::cout << std::endl;
    noisy_push_back(vector, 0);
    noisy_push_back(vector, 0);
    noisy_push_back(vector, 0);
    noisy_push_back(vector, 0);
    noisy_size(vector);

    std::cout << std::endl;
    noisy_clear(vector);
    noisy_size(vector);

    std::cout << std::endl;
    noisy_push_back(vector, 0);
    noisy_push_back(vector, 0);
    noisy_push_back(vector, 0);
    noisy_size(vector);
}

// Throws lots of stuff at the vector to make sure that growing doesn't crash
// and burn (but that it DOES grow rather than segfaulting)
void test6() {
    std::cout << "--- Test 6 output ---\n" << std::endl;

    Vector<int> vector;

    std::cout << "vector.push_back(0...499)" << std::endl;
    for (int i = 0; i < 500; i++) {
        vector.push_back(i);
    }

    std::cout << "assert vector[i] = i for all i 0...499" << std::endl;
    for (int i = 0; i < 500; i++) {
        if (vector[i] != i) {
            std::cerr << "\nERROR: vector[" << i << "] = " << vector[i] << ", but it should be " << i << std::endl;
            return;
        }
    }

    std::cout << std::endl << "vector.insert(500...999, 0)" << std::endl;
    for (int i = 500; i < 1000; i++) {
        vector.insert(i, 0);
    }

    std::cout << "assert vector[i] = 999 - i for all i 0...499" << std::endl;
    for (int i = 0; i < 500; i++) {
        if (vector[i] != 999 - i) {
            std::cerr << "\nERROR: vector[" << i << "] = " << vector[i] << ", but it should be " << 999 - i << std::endl;
            return;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        std::cerr << "You must specify which tests you would like to run (your options are 1, 2, 3, 4,\n"
            "5, 6, and all). You can specify several options by separating them by spaces."
            << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (std::strcmp(argv[i], "1") == 0) {
            test1();
        } else if (std::strcmp(argv[i], "2") == 0) {
            test2();
        } else if (std::strcmp(argv[i], "3") == 0) {
            test3();
        } else if (std::strcmp(argv[i], "4") == 0) {
            test4();
        } else if (std::strcmp(argv[i], "5") == 0) {
            test5();
        } else if (std::strcmp(argv[i], "6") == 0) {
            test6();
        } else if (std::strcmp(argv[i], "all") == 0) {
            test1();
            std::cout << std::endl;

            test2();
            std::cout << std::endl;

            test3();
            std::cout << std::endl;

            test4();
            std::cout << std::endl;

            test5();
            std::cout << std::endl;

            test6();
        } else {
            std::cerr << argv[i] << " isn't a valid option (1, 2, 3, 4, 5, 6, or all)" << std::endl;
        }

        if (i + 1 != argc) {
            std::cout << std::endl;
        }
    }

    return 0;
}
