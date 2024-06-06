#include <cstring>
#include <iostream>
#include <string>

#include "HashSet.h"

// --------- HELPER FUNCTIONS --------- 

template<class T>
void noisy_insert(HashSet<T>& set, T item) {
    std::cout << "set.insert(" << item << ") = " << std::boolalpha << set.insert(item) << std::endl;
}

template<class T>
void noisy_remove(HashSet<T>& set, T item) {
    std::cout << "set.remove(" << item << ") = " << std::boolalpha << set.remove(item) << std::endl;
}

template<class T>
void noisy_contains(const HashSet<T>& set, T item) {
    std::cout << "set.contains(" << item << ") = " << std::boolalpha << set.contains(item) << std::endl;
}

template<class T>
void noisy_clear(HashSet<T>& set) {
    set.clear();
    std::cout << "set.clear()" << std::endl;
}

template<class T>
void noisy_size(const HashSet<T>& set) {
    std::cout << "set.size() = " << set.size() << std::endl;
}

// --------- END HELPER FUNCTIONS --------- 

// Checks that insert works
void test1() {
    std::cout << "--- Test 1 output ---\n" << std::endl;

    HashSet<int> set;

    noisy_insert(set, 1);
    noisy_insert(set, 2);
    noisy_insert(set, 3);
    noisy_insert(set, 4);
    noisy_insert(set, 5);

    std::cout << std::endl;
    noisy_insert(set, 1);
    noisy_insert(set, 2);
    noisy_insert(set, 3);
    noisy_insert(set, 4);
    noisy_insert(set, 5);

    std::cout << std::endl;
    noisy_insert(set, 6);
    noisy_insert(set, 6);
}

// Checks that contains works
void test2() {
    std::cout << "--- Test 2 output ---\n" << std::endl;

    HashSet<int> set;

    noisy_insert(set, 2);
    noisy_insert(set, 3);
    noisy_insert(set, 4);
    noisy_insert(set, 6);
    noisy_insert(set, 7);
    noisy_insert(set, 10);

    std::cout << std::endl;
    noisy_contains(set, 1);
    noisy_contains(set, 2);
    noisy_contains(set, 3);
    noisy_contains(set, 4);
    noisy_contains(set, 5);
    noisy_contains(set, 6);
    noisy_contains(set, 7);
    noisy_contains(set, 8);
    noisy_contains(set, 9);
    noisy_contains(set, 10);
}

// Checks that remove works
void test3() {
    std::cout << "--- Test 3 output ---\n" << std::endl;

    HashSet<std::string> set;

    noisy_insert<std::string>(set, "quilt");
    noisy_insert<std::string>(set, "pineapple");
    noisy_insert<std::string>(set, "utopia");
    noisy_insert<std::string>(set, "unity");

    std::cout << std::endl;
    noisy_remove<std::string>(set, "quilt");
    noisy_remove<std::string>(set, "utopia");
    noisy_remove<std::string>(set, "seahorse");

    std::cout << std::endl;
    noisy_contains<std::string>(set, "quilt");
    noisy_contains<std::string>(set, "pineapple");
    noisy_contains<std::string>(set, "utopia");
    noisy_contains<std::string>(set, "unity");
    noisy_contains<std::string>(set, "seahorse");
}

// Checks that size and clear work
void test4() {
    std::cout << "--- Test 4 output ---\n" << std::endl;

    HashSet<std::string> set;
    noisy_size(set);

    std::cout << std::endl;
    noisy_insert<std::string>(set, "laughter");
    noisy_insert<std::string>(set, "freedom");
    noisy_insert<std::string>(set, "igloo");
    noisy_size(set);

    std::cout << std::endl;
    noisy_insert<std::string>(set, "laughter");
    noisy_insert<std::string>(set, "igloo");
    noisy_size(set);

    std::cout << std::endl;
    noisy_remove<std::string>(set, "freedom");
    noisy_remove<std::string>(set, "igloo");
    noisy_size(set);

    std::cout << std::endl;
    noisy_remove<std::string>(set, "igloo");
    noisy_size(set);

    std::cout << std::endl;
    noisy_clear(set);
    noisy_size(set);

    std::cout << std::endl;
    noisy_insert<std::string>(set, "elephant");
    noisy_insert<std::string>(set, "violin");
    noisy_size(set);

    std::cout << std::endl;
    noisy_contains<std::string>(set, "laughter");
    noisy_contains<std::string>(set, "freedom");
    noisy_contains<std::string>(set, "igloo");
    noisy_contains<std::string>(set, "elephant");
    noisy_contains<std::string>(set, "violin");
}

// Throws lots of stuff at the hash set to make sure that rehashing doesn't
// crash and burn
void test5() {
    std::cout << "--- Test 5 output ---\n" << std::endl;

    HashSet<int> set;

    std::cout << "set.insert(0...999)" << std::endl;
    for (int i = 0; i < 1000; i++) {
        set.insert(i);
    }

    std::cout << "assert set.contains(i) for all i 0...999" << std::endl;
    for (int i = 0; i < 1000; i++) {
        if (!set.contains(i)) {
            std::cerr << "\nERROR: set.contains(" << i << ") = false, but it should be true" << std::endl;
            return;
        }
    }
}

int main(int argc, char const* argv[]) {
    if (argc <= 1) {
        std::cerr << "You must specify which tests you would like to run (your options are 1, 2, 3, 4,\n"
            "5, and all). You can specify several options by separating them by spaces."
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
        } else {
            std::cerr << argv[i] << " isn't a valid option (1, 2, 3, 4, 5, or all)" << std::endl;
        }

        if (i + 1 != argc) {
            std::cout << std::endl;
        }
    }

    return 0;
}
