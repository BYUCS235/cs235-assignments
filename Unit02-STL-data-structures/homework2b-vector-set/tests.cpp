#include <cstring>
#include <iostream>
#include <string>

#include "VectorSet.h"

// --------- HELPER FUNCTIONS --------- 

template<class T>
void noisy_contains(VectorSet<T>& set, T item) {
    std::cout << "set.contains(" << item << ") = " << std::boolalpha << set.contains(item) << std::endl;
}

template<class T>
void noisy_insert(VectorSet<T>& set, T item) {
    std::cout << "set.insert(" << item << ") = " << std::boolalpha << set.insert(item) << std::endl;
}

template<class T>
void noisy_remove(VectorSet<T>& set, T item) {
    std::cout << "set.remove(" << item << ") = " << std::boolalpha << set.remove(item) << std::endl;
}

template<class T>
void noisy_size(const VectorSet<T>& set) {
    std::cout << "set.size() = " << set.size() << std::endl;
}

template<class T>
void noisy_empty(const VectorSet<T>& set) {
    std::cout << "set.empty() = " << std::boolalpha << set.empty() << std::endl;
}

template<class T>
void noisy_clear(VectorSet<T>& set) {
    std::cout << "set.clear()" << std::endl;
    set.clear();
}

// --------- END HELPER FUNCTIONS --------- 

// Checks that insert and contains work
void test1() {
    std::cout << "--- Test 1 output ---\n" << std::endl;

    VectorSet<int> set;

    noisy_insert(set, 10);
    noisy_insert(set, 4);
    noisy_insert(set, 5);
    noisy_insert(set, 2);
    noisy_insert(set, 10);

    std::cout << std::endl;

    for (int i = 1; i <= 10; i++) {
        noisy_contains(set, i);
    }
}

// Checks that remove works
void test2() {
    std::cout << "--- Test 2 output ---\n" << std::endl;

    VectorSet<std::string> set;

    set.insert("candle");
    set.insert("chair");
    set.insert("circle");
    set.insert("donkey");
    set.insert("dragon");
    set.insert("guitar");
    set.insert("spring");

    std::cout << "set = {candle, chair, circle, donkey, dragon, guitar, spring}" << std::endl;
    std::cout << std::endl;

    noisy_remove<std::string>(set, "spring");
    noisy_remove<std::string>(set, "donkey");
    noisy_remove<std::string>(set, "chair");
    noisy_remove<std::string>(set, "coffee");
    noisy_remove<std::string>(set, "guitar");
    noisy_remove<std::string>(set, "chair");
    noisy_remove<std::string>(set, "candle");
    noisy_remove<std::string>(set, "circle");
    noisy_remove<std::string>(set, "dragon");
    noisy_remove<std::string>(set, "guitar");
}

// Checks that empty and size work
void test3() {
    std::cout << "--- Test 3 output ---\n" << std::endl;

    VectorSet<std::string> set;

    noisy_empty(set);

    std::cout << std::endl;

    noisy_insert<std::string>(set, "bottle");
    noisy_insert<std::string>(set, "flower");
    noisy_size(set);

    std::cout << std::endl;

    noisy_insert<std::string>(set, "bottle");
    noisy_size(set);

    std::cout << std::endl;

    noisy_insert<std::string>(set, "orange");
    noisy_size(set);

    std::cout << std::endl;

    noisy_remove<std::string>(set, "bottle");
    noisy_remove<std::string>(set, "butter");
    noisy_size(set);

    std::cout << std::endl;

    noisy_insert<std::string>(set, "bottle");
    noisy_size(set);

    std::cout << std::endl;

    noisy_remove<std::string>(set, "flower");
    noisy_remove<std::string>(set, "orange");
    noisy_remove<std::string>(set, "bottle");
    noisy_size(set);

    std::cout << std::endl;

    noisy_empty(set);
}

// Checks that clear works
void test4() {
    std::cout << "--- Test 4 output ---\n" << std::endl;

    VectorSet<int> set;

    set.insert(4);
    set.insert(6);
    set.insert(7);
    set.insert(15);
    set.insert(16);
    set.insert(19);
    set.insert(23);
    set.insert(29);

    std::cout << "set = {4, 6, 7, 15, 16, 19, 23, 29}" << std::endl;
    noisy_size(set);
    noisy_empty(set);

    std::cout << std::endl;

    noisy_clear(set);

    std::cout << std::endl;

    noisy_size(set);
    noisy_empty(set);

    std::cout << std::endl;

    noisy_insert(set, 4);
    noisy_size(set);
    noisy_empty(set);
}

int main(int argc, char const* argv[]) {
    if (argc <= 1) {
        std::cerr << "You must specify which tests you would like to run (your options are 1, 2, 3, 4,\n"
            "and all). You can specify several options by separating them by spaces."
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
        } else if (std::strcmp(argv[i], "all") == 0) {
            test1();
            std::cout << std::endl;

            test2();
            std::cout << std::endl;

            test3();
            std::cout << std::endl;

            test4();
        } else {
            std::cerr << argv[i] << " isn't a valid option (1, 2, 3, 4, or all)" << std::endl;
        }

        if (i + 1 != argc) {
            std::cout << std::endl;
        }
    }

    return 0;
}
