#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#include "QS.h"

// --------- HELPER FUNCTIONS --------- 

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& array) {
    bool print_space = false;
    for (const T& elem : array) {
        if (print_space) {
            os << ' ';
        }
        print_space = true;
        os << elem;
    }
    return os;
}

template<class T>
void noisy_medianOfThree(std::vector<T>& array, int left, int right) {
    int index = medianOfThree(array, left, right);
    std::cout << std::endl;
    std::cout << "medianOfThree(array, " << left << ", " << right << ") = " << index << std::endl;
    std::cout << "array = " << array << std::endl;
}

template<class T>
void noisy_partition(std::vector<T>& array, int left, int right) {
    int index = partition(array, left, right);
    std::cout << std::endl;
    std::cout << "partition(array, " << left << ", " << right << ") = " << index << std::endl;
    std::cout << "array = " << array << std::endl;
}

template<class T>
void noisy_sort(std::vector<T>& array) {
    std::cout << "array = " << array << std::endl;
    std::cout << "Sorting array..." << std::endl;
    sort(array);
    std::cout << "array = " << array << std::endl;
}

// --------- END HELPER FUNCTIONS --------- 

// Checks that medianOfThree works
void test1() {
    std::cout << "--- Test 1 output ---\n" << std::endl;

    std::vector<int> array{ -3, 4, 4, 8, -4, 4, 2, -6, 6, 5 };

    std::cout << "array = " << array << std::endl;
    noisy_medianOfThree(array, 0, 9);
    noisy_medianOfThree(array, 1, 6);
    noisy_medianOfThree(array, 2, 7);
    noisy_medianOfThree(array, 6, 8);
    noisy_medianOfThree(array, 7, 9);
    noisy_medianOfThree(array, 2, 4);
}

// Checks that partition works with sorted data
void test2() {
    std::cout << "--- Test 2 output ---\n" << std::endl;

    std::vector<int> array{ 1, 2, 3, 4, 5, 9, 13, 16, 16, 17 };

    std::cout << "array = " << array << std::endl;
    noisy_partition(array, 0, 4);
    noisy_partition(array, 3, 9);
    noisy_partition(array, 0, 9);
}

// Checks that partition works with reversed data
void test3() {
    std::cout << "--- Test 3 output ---\n" << std::endl;

    std::vector<std::string> array{ "velvet", "pillow", "pillow", "ocean", "mountain", "coffee", "cascade", "bubble", "blossom", "bicycle" };

    std::cout << "array = " << array << std::endl;
    noisy_partition(array, 0, 4);
    noisy_partition(array, 3, 9);
    noisy_partition(array, 0, 9);
}

// Checks that partition works with shuffled data
void test4() {
    std::cout << "--- Test 4 output ---\n" << std::endl;

    std::vector<int> array{ 6, 14, 19, 5, 7, 1, 18, 16, 8, 16 };

    std::cout << "array = " << array << std::endl;
    noisy_partition(array, 0, 4);
    noisy_partition(array, 3, 9);
    noisy_partition(array, 0, 9);
}

// Checks that sort works with sorted data
void test5() {
    std::cout << "--- Test 5 output ---\n" << std::endl;

    std::vector<int> array{ 1, 7, 8, 9, 11, 11, 15, 16, 18, 20 };
    noisy_sort(array);
}

// Checks that sort works with reversed data
void test6() {
    std::cout << "--- Test 6 output ---\n" << std::endl;

    std::vector<int> array{ 20, 14, 8, 8, 6, 5, 5, 5, 4, 4 };
    noisy_sort(array);
}

// Checks that sort works with shuffled data
void test7() {
    std::cout << "--- Test 7 output ---\n" << std::endl;

    std::vector<std::string> array{ "whisper", "coffee", "kaleidoscope", "coffee", "firefly", "marshmallow", "cascade", "bicycle", "aurora", "pillow" };
    noisy_sort(array);
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        std::cerr << "You must specify which tests you would like to run (your options are 1, 2, 3, 4,\n"
            "5, 6, 7, and all). You can specify several options by separating them by spaces."
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
        } else if (std::strcmp(argv[i], "7") == 0) {
            test7();
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
            std::cout << std::endl;

            test7();
        } else {
            std::cerr << argv[i] << " isn't a valid option (1, 2, 3, 4, 5, 6, 7, or all)" << std::endl;
        }

        if (i + 1 != argc) {
            std::cout << std::endl;
        }
    }

    return 0;
}
