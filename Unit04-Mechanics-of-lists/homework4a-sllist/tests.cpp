#include <cstring>
#include <initializer_list>
#include <iostream>
#include <string>

#include "SLList.h"

// --------- HELPER FUNCTIONS --------- 

template<class T>
void noisy_push_back(SLList<T>& list, T item) {
    list.push_back(item);
    std::cout << "list.push_back(" << item << ')' << std::endl;
}

template<class T>
void noisy_pop_back(SLList<T>& list) {
    list.pop_back();
    std::cout << "list.pop_back()" << std::endl;
}

template<class T>
void noisy_front(const SLList<T>& list) {
    std::cout << "list.front() = " << list.front() << std::endl;
}

template<class T>
void noisy_size(const SLList<T>& list) {
    std::cout << "list.size() = " << list.size() << std::endl;
}

template<class T>
void noisy_clear(SLList<T>& list) {
    list.clear();
    std::cout << "list.clear()" << std::endl;
}

template<class T>
void print_list(const SLList<T>& list) {
    std::cout << "list =";
    const typename SLList<T>::Node* node = list.get_head();
    while (node != nullptr) {
        std::cout << ' ' << node->value;
        node = node->next;
    }
    std::cout << std::endl;
}

// --------- END HELPER FUNCTIONS --------- 

// Checks that push_back works
void test1() {
    std::cout << "--- Test 1 output ---\n" << std::endl;

    SLList<int> list;

    noisy_push_back(list, 1);
    print_list(list);

    std::cout << std::endl;
    noisy_push_back(list, 2);
    print_list(list);

    std::cout << std::endl;
    noisy_push_back(list, 3);
    print_list(list);

    std::cout << std::endl;
    noisy_push_back(list, 4);
    print_list(list);

    std::cout << std::endl;
    noisy_push_back(list, 5);
    print_list(list);
}

// Checks that pop_back works
void test2() {
    std::cout << "--- Test 2 output ---\n" << std::endl;

    SLList<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    print_list(list);

    std::cout << std::endl;
    noisy_pop_back(list);
    print_list(list);

    std::cout << std::endl;
    noisy_pop_back(list);
    print_list(list);

    std::cout << std::endl;
    noisy_pop_back(list);
    print_list(list);

    std::cout << std::endl;
    noisy_pop_back(list);
    print_list(list);

    std::cout << std::endl;
    noisy_pop_back(list);
    print_list(list);
}

// Checks that front works
void test3() {
    std::cout << "--- Test 3 output ---\n" << std::endl;

    SLList<std::string> list;

    noisy_push_back<std::string>(list, "kindness");
    noisy_push_back<std::string>(list, "peace");
    noisy_front(list);

    std::cout << std::endl;
    noisy_pop_back(list);
    noisy_pop_back(list);
    noisy_push_back<std::string>(list, "zebra");
    noisy_front(list);

    std::cout << std::endl;
    noisy_pop_back(list);
    noisy_push_back<std::string>(list, "joy");
    noisy_front(list);
}

// Checks that size and clear work
void test4() {
    std::cout << "--- Test 4 output ---\n" << std::endl;

    SLList<int> list;
    noisy_size(list);

    std::cout << std::endl;
    noisy_push_back(list, 2);
    noisy_push_back(list, 5);
    noisy_size(list);

    std::cout << std::endl;
    noisy_pop_back(list);
    noisy_size(list);

    std::cout << std::endl;
    noisy_clear(list);
    noisy_size(list);

    std::cout << std::endl;
    noisy_push_back(list, 6);
    noisy_push_back(list, 7);
    noisy_push_back(list, 9);
    noisy_size(list);
}

int main(int argc, char* argv[]) {
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
