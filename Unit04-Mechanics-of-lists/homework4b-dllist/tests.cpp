#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string>

#include "DLList.h"

// --------- HELPER FUNCTIONS --------- 

template<class T>
void noisy_push_front(DLList<T>& list, T item) {
    list.push_front(item);
    std::cout << "list.push_front(" << item << ')' << std::endl;
}

template<class T>
void noisy_push_back(DLList<T>& list, T item) {
    list.push_back(item);
    std::cout << "list.push_back(" << item << ')' << std::endl;
}

template<class T>
void noisy_insert(DLList<T>& list, T item, int position) {
    try {
        list.insert(item, position);
        std::cout << "list.insert(" << item << ", " << position << ')' << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "list.insert(" << item << ", " << position << ") threw an out_of_range exception" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "list.insert(" << item << ", " << position << ") threw an exception: " << e.what() << std::endl;
    }
}

template<class T>
void noisy_pop_front(DLList<T>& list) {
    try {
        list.pop_front();
        std::cout << "list.pop_front()" << std::endl;
    } catch (const std::length_error& e) {
        std::cout << "list.pop_front() threw a length_error exception" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "list.pop_front() threw an exception: " << e.what() << std::endl;
    }
}

template<class T>
void noisy_pop_back(DLList<T>& list) {
    try {
        list.pop_back();
        std::cout << "list.pop_back()" << std::endl;
    } catch (const std::length_error& e) {
        std::cout << "list.pop_back() threw a length_error exception" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "list.pop_back() threw an exception: " << e.what() << std::endl;
    }
}

template<class T>
void noisy_remove(DLList<T>& list, int position) {
    try {
        list.remove(position);
        std::cout << "list.remove(" << position << ')' << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "list.remove(" << position << ") threw an out_of_range exception" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "list.remove(" << position << ") threw an exception: " << e.what() << std::endl;
    }
}

template<class T>
void noisy_front(const DLList<T>& list) {
    try {
        T item = list.front();
        std::cout << "list.front() = " << item << std::endl;
    } catch (const std::length_error& e) {
        std::cout << "list.front() threw a length_error exception" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "list.front() threw an exception: " << e.what() << std::endl;
    }
}

template<class T>
void noisy_back(const DLList<T>& list) {
    try {
        T item = list.back();
        std::cout << "list.back() = " << item << std::endl;
    } catch (const std::length_error& e) {
        std::cout << "list.back() threw a length_error exception" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "list.back() threw an exception: " << e.what() << std::endl;
    }
}

template<class T>
void noisy_at(const DLList<T>& list, int index) {
    try {
        T item = list.at(index);
        std::cout << "list.at(" << index << ") = " << item << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "list.at(" << index << ") threw an out_of_range exception" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "list.at(" << index << ") threw an exception: " << e.what() << std::endl;
    }
}

template<class T>
void noisy_contains(const DLList<T>& list, const T& item) {
    std::cout << "list.contains(" << item << ") = " << std::boolalpha << list.contains(item) << std::endl;
}

template<class T>
void noisy_size(const DLList<T>& list) {
    std::cout << "list.size() = " << list.size() << std::endl;
}

template<class T>
void noisy_clear(DLList<T>& list) {
    list.clear();
    std::cout << "list.clear()" << std::endl;
}

template<class T>
void print_list(const DLList<T>& list) {
    std::cout << "list =";
    const typename DLList<T>::Node* node = list.get_head();
    while (node != nullptr) {
        std::cout << ' ' << node->value;
        node = node->next;
    }
    std::cout << std::endl;
}

// --------- END HELPER FUNCTIONS --------- 

// Checks that push_front and push_back work
void test1() {
    std::cout << "--- Test 1 output ---\n" << std::endl;

    DLList<int> list;

    noisy_push_front(list, 5);
    noisy_push_front(list, 9);
    noisy_push_back(list, 9);
    print_list(list);

    std::cout << std::endl;

    noisy_push_back(list, 16);
    noisy_push_back(list, 15);
    noisy_push_front(list, 7);
    print_list(list);

    std::cout << std::endl;

    noisy_push_front(list, 6);
    noisy_push_front(list, 3);
    noisy_push_front(list, 10);
    noisy_push_back(list, 3);
    print_list(list);
}

// Checks that insert works
void test2() {
    std::cout << "--- Test 2 output ---\n" << std::endl;

    DLList<std::string> list;

    noisy_insert<std::string>(list, "monkey", 0);
    noisy_insert<std::string>(list, "hammer", 0);
    noisy_insert<std::string>(list, "opulent", 2);
    print_list(list);

    std::cout << std::endl;

    noisy_insert<std::string>(list, "octopus", 6);
    noisy_insert<std::string>(list, "octopus", 2);
    noisy_insert<std::string>(list, "kindness", 1);
    print_list(list);

    std::cout << std::endl;

    noisy_push_back<std::string>(list, "inspiration");
    noisy_push_front<std::string>(list, "ostrich");
    print_list(list);
}

// Checks that front and back work
void test3() {
    std::cout << "--- Test 3 output ---\n" << std::endl;

    DLList<int> list;

    noisy_front(list);
    noisy_back(list);

    std::cout << std::endl;

    noisy_push_front(list, 2);
    noisy_front(list);
    noisy_back(list);
    print_list(list);

    std::cout << std::endl;

    noisy_push_back(list, 5);
    noisy_push_back(list, 8);
    noisy_front(list);
    noisy_back(list);
    print_list(list);

    std::cout << std::endl;

    noisy_insert(list, 12, 3);
    noisy_back(list);
    noisy_insert(list, 4, 3);
    noisy_back(list);
    print_list(list);

    std::cout << std::endl;

    noisy_insert(list, 0, 0);
    noisy_front(list);
    noisy_insert(list, 3, 1);
    noisy_front(list);
    print_list(list);
}

// Checks that at works
void test4() {
    std::cout << "--- Test 4 output ---\n" << std::endl;

    DLList<std::string> list;

    noisy_at(list, 0);
    noisy_push_front<std::string>(list, "apple");
    noisy_at(list, 0);
    noisy_push_back<std::string>(list, "xylophone");
    noisy_push_front<std::string>(list, "honey");
    noisy_at(list, 2);
    noisy_at(list, 3);
    print_list(list);

    std::cout << std::endl;

    noisy_insert<std::string>(list, "gratitude", 1);
    noisy_at(list, 1);
    noisy_insert<std::string>(list, "nest", 4);
    noisy_at(list, 4);
    print_list(list);

    std::cout << std::endl;

    noisy_insert<std::string>(list, "utopia", 0);
    noisy_at(list, 0);
    print_list(list);
}

// Checks that contains works
void test5() {
    std::cout << "--- Test 5 output ---\n" << std::endl;

    DLList<int> list;

    list.push_front(4);
    list.push_front(8);
    list.push_front(5);
    list.push_front(9);
    list.push_front(8);
    list.push_front(2);
    list.push_front(10);
    list.push_front(7);

    print_list(list);
    noisy_contains(list, 1);
    noisy_contains(list, 2);
    noisy_contains(list, 3);
    noisy_contains(list, 4);
    noisy_contains(list, 5);
    noisy_contains(list, 6);
    noisy_contains(list, 7);
    noisy_contains(list, 8);
    noisy_contains(list, 9);
    noisy_contains(list, 10);
}

// Checks that pop_front and pop_back work
void test6() {
    std::cout << "--- Test 6 output ---\n" << std::endl;

    DLList<std::string> list;

    list.push_front("quilt");
    list.push_front("bliss");
    list.push_front("rainbow");
    list.push_front("tranquility");
    list.push_front("candle");

    print_list(list);
    noisy_pop_front(list);
    noisy_pop_back(list);
    print_list(list);

    std::cout << std::endl;

    noisy_pop_front(list);
    noisy_pop_front(list);
    print_list(list);

    std::cout << std::endl;

    noisy_pop_back(list);
    noisy_pop_front(list);
    noisy_pop_front(list);
}

// Checks that remove works
void test7() {
    std::cout << "--- Test 7 output ---\n" << std::endl;

    DLList<int> list;

    list.push_front(3);
    list.push_front(14);
    list.push_front(5);
    list.push_front(11);
    list.push_front(19);
    list.push_front(20);
    list.push_front(15);
    list.push_front(11);
    list.push_front(14);
    list.push_front(15);

    print_list(list);
    noisy_remove(list, 3);

    std::cout << std::endl;

    print_list(list);
    noisy_remove(list, 0);
    noisy_remove(list, 0);
    noisy_remove(list, 0);
    noisy_remove(list, 5);
    noisy_remove(list, 4);
    noisy_remove(list, 3);

    std::cout << std::endl;

    print_list(list);
    noisy_remove(list, 1);
    print_list(list);
    noisy_remove(list, 1);
    print_list(list);
    noisy_remove(list, 0);

    std::cout << std::endl;

    print_list(list);
    noisy_front(list);
    noisy_back(list);
    noisy_pop_front(list);
    noisy_pop_back(list);
    noisy_at(list, 3);
}

// Checks that size and clear work
void test8() {
    std::cout << "--- Test 8 output ---\n" << std::endl;

    DLList<int> list;

    noisy_size(list);
    noisy_push_front(list, 2);
    noisy_size(list);
    noisy_push_back(list, 5);
    noisy_size(list);

    std::cout << std::endl;

    noisy_insert(list, 3, 1);
    noisy_size(list);
    noisy_insert(list, 19, 4);
    noisy_size(list);

    std::cout << std::endl;

    noisy_push_front(list, 10);
    noisy_push_front(list, 3);
    noisy_push_front(list, 1);
    noisy_size(list);

    std::cout << std::endl;

    noisy_remove(list, 1);
    noisy_size(list);
    noisy_pop_front(list);
    noisy_size(list);
    noisy_pop_back(list);
    noisy_size(list);
    noisy_remove(list, 8);
    noisy_size(list);

    std::cout << std::endl;

    noisy_clear(list);
    noisy_size(list);

    std::cout << std::endl;

    noisy_pop_front(list);
    noisy_size(list);
    noisy_pop_back(list);
    noisy_size(list);
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        std::cerr << "You must specify which tests you would like to run (your options are 1, 2, 3, 4, 5,\n"
            "6, 7, 8, and all). You can specify several options by separating them by spaces."
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
        } else if (std::strcmp(argv[i], "8") == 0) {
            test8();
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
            std::cout << std::endl;

            test8();
        } else {
            std::cerr << argv[i] << " isn't a valid option (1, 2, 3, 4, 5, 6, 7, 8, or all)" << std::endl;
        }

        if (i + 1 != argc) {
            std::cout << std::endl;
        }
    }

    return 0;
}
