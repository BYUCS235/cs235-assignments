#include <cstring>
#include <iostream>
#include <string>

#include "AVL.h"
#include "printing.h"

// --------- HELPER FUNCTIONS --------- 

void noisy_insert(AVL<int>& tree, int item) {
    std::cout << "tree.insert(" << item << ") = " << std::boolalpha << tree.insert(item) << std::endl;
}

void noisy_remove(AVL<int>& tree, int item) {
    std::cout << "tree.remove(" << item << ") = " << std::boolalpha << tree.remove(item) << std::endl;
}

void check_and_remove_head(AVL<int>& tree) {
    std::cout << std::endl;
    std::cout << "root->value = " << tree.getRootNode()->value << std::endl;
    noisy_remove(tree, tree.getRootNode()->value);
}

void noisy_contains(const AVL<int>& tree, int item) {
    std::cout << "tree.contains(" << item << ") = " << std::boolalpha << tree.contains(item) << std::endl;
}

void noisy_clear(AVL<int>& tree) {
    tree.clear();
    std::cout << "tree.clear()" << std::endl;
}

void noisy_size(const AVL<int>& tree) {
    std::cout << "tree.size() = " << tree.size() << std::endl;
}

// --------- END HELPER FUNCTIONS --------- 

// Checks that insert works with a small tree that has a RR imbalance
void test1() {
    std::cout << "--- Test 1 output ---\n" << std::endl;

    AVL<int> tree;

    noisy_insert(tree, 1);
    std::cout << std::endl;
    pretty_print_tree(tree);

    std::cout << std::endl;
    noisy_insert(tree, 2);
    std::cout << std::endl;
    pretty_print_tree(tree);

    std::cout << std::endl;
    noisy_insert(tree, 3);
    std::cout << std::endl;
    pretty_print_tree(tree);
}

// Checks that insert works with a small tree that has a LL imbalance
void test2() {
    std::cout << "--- Test 2 output ---\n" << std::endl;

    AVL<int> tree;

    noisy_insert(tree, 3);
    std::cout << std::endl;
    pretty_print_tree(tree);

    std::cout << std::endl;
    noisy_insert(tree, 2);
    std::cout << std::endl;
    pretty_print_tree(tree);

    std::cout << std::endl;
    noisy_insert(tree, 1);
    std::cout << std::endl;
    pretty_print_tree(tree);
}

// Checks that insert works with a small subtree that has a LL imbalance
void test3() {
    std::cout << "--- Test 3 output ---\n" << std::endl;

    AVL<int> tree;

    tree.insert(4);
    tree.insert(5);
    tree.insert(3);
    tree.insert(2);

    pretty_print_tree(tree);

    std::cout << std::endl;
    noisy_insert(tree, 1);
    std::cout << std::endl;
    pretty_print_tree(tree);
}

// Checks that insert works with a small subtree that has a LR imbalance
void test4() {
    std::cout << "--- Test 4 output ---\n" << std::endl;

    AVL<int> tree;

    tree.insert(4);
    tree.insert(5);
    tree.insert(3);
    tree.insert(1);
    pretty_print_tree(tree);

    std::cout << std::endl;
    noisy_insert(tree, 2);
    std::cout << std::endl;
    pretty_print_tree(tree);
}

// Checks that insert works with a small subtree that has a RR imbalance
void test5() {
    std::cout << "--- Test 5 output ---\n" << std::endl;

    AVL<int> tree;

    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    tree.insert(4);
    pretty_print_tree(tree);

    std::cout << std::endl;
    noisy_insert(tree, 5);
    std::cout << std::endl;
    pretty_print_tree(tree);
}

// Checks that insert works with a small subtree that has a RL imbalance
void test6() {
    std::cout << "--- Test 6 output ---\n" << std::endl;

    AVL<int> tree;

    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    pretty_print_tree(tree);

    std::cout << std::endl;
    noisy_insert(tree, 4);
    std::cout << std::endl;
    pretty_print_tree(tree);
}

// Checks that insert works with a big tree that has a RR imbalance
void test7() {
    std::cout << "--- Test 7 output ---\n" << std::endl;

    AVL<int> tree;

    tree.insert(4);
    tree.insert(2);
    tree.insert(8);
    tree.insert(1);
    tree.insert(3);
    tree.insert(6);
    tree.insert(10);
    tree.insert(5);
    tree.insert(7);
    tree.insert(9);
    tree.insert(11);
    pretty_print_tree(tree);

    std::cout << std::endl;
    noisy_insert(tree, 12);
    std::cout << std::endl;
    pretty_print_tree(tree);
}

// Checks that insert works with a big tree that has a RL imbalance
void test8() {
    std::cout << "--- Test 8 output ---\n" << std::endl;

    AVL<int> tree;

    tree.insert(4);
    tree.insert(2);
    tree.insert(9);
    tree.insert(1);
    tree.insert(3);
    tree.insert(6);
    tree.insert(11);
    tree.insert(5);
    tree.insert(7);
    tree.insert(10);
    tree.insert(12);
    pretty_print_tree(tree);

    std::cout << std::endl;
    noisy_insert(tree, 8);
    std::cout << std::endl;
    pretty_print_tree(tree);
}

// Checks that insert works with a big tree that has a LL imbalance
void test9() {
    std::cout << "--- Test 9 output ---\n" << std::endl;

    AVL<int> tree;

    tree.insert(9);
    tree.insert(5);
    tree.insert(11);
    tree.insert(3);
    tree.insert(7);
    tree.insert(10);
    tree.insert(12);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    pretty_print_tree(tree);

    std::cout << std::endl;
    noisy_insert(tree, 1);
    std::cout << std::endl;
    pretty_print_tree(tree);
}

// Checks that insert works with a big tree that has a LR imbalance
void test10() {
    std::cout << "--- Test 10 output ---\n" << std::endl;

    AVL<int> tree;

    tree.insert(9);
    tree.insert(4);
    tree.insert(11);
    tree.insert(2);
    tree.insert(7);
    tree.insert(10);
    tree.insert(12);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(8);
    pretty_print_tree(tree);

    std::cout << std::endl;
    noisy_insert(tree, 6);
    std::cout << std::endl;
    pretty_print_tree(tree);
}

// Checks that contains works
void test11() {
    std::cout << "--- Test 11 output ---\n" << std::endl;

    AVL<int> tree;

    tree.insert(8);
    tree.insert(4);
    tree.insert(12);
    tree.insert(2);
    tree.insert(6);
    tree.insert(10);
    tree.insert(14);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(9);
    tree.insert(11);
    tree.insert(13);
    tree.insert(15);
    pretty_print_tree(tree);

    std::cout << std::endl;
    noisy_contains(tree, 14);
    noisy_contains(tree, 4);
    noisy_contains(tree, 5);
    noisy_contains(tree, 15);
    noisy_contains(tree, 7);
    noisy_contains(tree, 2);
    noisy_contains(tree, -3);
    noisy_contains(tree, 17);
    noisy_contains(tree, 35);
}

// Checks that remove works with tree that has a LL imbalance
void test12() {
    std::cout << "--- Test 12 output ---\n" << std::endl;

    AVL<int> tree;

    tree.insert(6);
    tree.insert(4);
    tree.insert(7);
    tree.insert(2);
    tree.insert(5);
    tree.insert(9);
    tree.insert(1);
    tree.insert(3);
    pretty_print_tree(tree);

    std::cout << std::endl;
    noisy_remove(tree, 9);
    std::cout << std::endl;
    pretty_print_tree(tree);
}

// Checks that remove works with tree that has a LR imbalance
void test13() {
    std::cout << "--- Test 13 output ---\n" << std::endl;

    AVL<int> tree;

    tree.insert(6);
    tree.insert(2);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);
    tree.insert(9);
    tree.insert(3);
    tree.insert(5);
    pretty_print_tree(tree);

    std::cout << std::endl;
    noisy_remove(tree, 9);
    std::cout << std::endl;
    pretty_print_tree(tree);
}

// Checks that remove works with tree that has a RL imbalance
void test14() {
    std::cout << "--- Test 14 output ---\n" << std::endl;

    AVL<int> tree;

    tree.insert(4);
    tree.insert(3);
    tree.insert(8);
    tree.insert(2);
    tree.insert(6);
    tree.insert(9);
    tree.insert(5);
    tree.insert(7);
    pretty_print_tree(tree);

    std::cout << std::endl;
    noisy_remove(tree, 2);
    std::cout << std::endl;
    pretty_print_tree(tree);
}

// Checks that remove works with tree that has a RR imbalance
void test15() {
    std::cout << "--- Test 15 output ---\n" << std::endl;

    AVL<int> tree;

    tree.insert(4);
    tree.insert(3);
    tree.insert(6);
    tree.insert(2);
    tree.insert(5);
    tree.insert(8);
    tree.insert(7);
    tree.insert(9);
    pretty_print_tree(tree);

    std::cout << std::endl;
    noisy_remove(tree, 2);
    std::cout << std::endl;
    pretty_print_tree(tree);
}

// Stress tests remove by repeatedly removing the root node
void test16() {
    std::cout << "--- Test 16 output ---\n" << std::endl;

    AVL<int> tree;

    tree.insert(10);
    tree.insert(6);
    tree.insert(14);
    tree.insert(4);
    tree.insert(8);
    tree.insert(12);
    tree.insert(16);
    tree.insert(2);
    tree.insert(5);
    tree.insert(7);
    tree.insert(11);
    tree.insert(13);
    tree.insert(15);
    tree.insert(17);
    tree.insert(1);
    tree.insert(3);
    pretty_print_tree(tree);

    std::cout << std::endl;
    noisy_remove(tree, 10);
    std::cout << std::endl;
    pretty_print_tree(tree);

    check_and_remove_head(tree);
    check_and_remove_head(tree);
    check_and_remove_head(tree);
    check_and_remove_head(tree);
    check_and_remove_head(tree);
    check_and_remove_head(tree);
    check_and_remove_head(tree);
    check_and_remove_head(tree);
    check_and_remove_head(tree);
    check_and_remove_head(tree);
    check_and_remove_head(tree);
    check_and_remove_head(tree);
    check_and_remove_head(tree);
    check_and_remove_head(tree);
    check_and_remove_head(tree);

    std::cout << std::endl;
    noisy_size(tree);
}

// Checks that insert works after calling remove
void test17() {
    std::cout << "--- Test 17 output ---\n" << std::endl;

    AVL<int> tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(1);
    pretty_print_tree(tree);

    std::cout << std::endl;
    noisy_remove(tree, 6);
    std::cout << std::endl;
    pretty_print_tree(tree);

    std::cout << std::endl;
    noisy_insert(tree, 8);
    std::cout << std::endl;
    pretty_print_tree(tree);
}

// Checks that size and clear work
void test18() {
    std::cout << "--- Test 18 output ---\n" << std::endl;

    AVL<int> tree;

    noisy_size(tree);

    std::cout << std::endl;
    noisy_insert(tree, 1);
    noisy_insert(tree, 2);
    noisy_insert(tree, 3);
    noisy_size(tree);

    std::cout << std::endl;
    noisy_insert(tree, 1);
    noisy_insert(tree, 3);
    noisy_size(tree);

    std::cout << std::endl;
    noisy_remove(tree, 2);
    noisy_remove(tree, 1);
    noisy_size(tree);

    std::cout << std::endl;
    noisy_remove(tree, 1);
    noisy_size(tree);

    std::cout << std::endl;
    noisy_remove(tree, 3);
    noisy_size(tree);

    std::cout << std::endl;
    noisy_insert(tree, 5);
    noisy_insert(tree, 7);
    noisy_size(tree);

    std::cout << std::endl;
    noisy_clear(tree);
    noisy_size(tree);
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        std::cerr << "You must specify which tests you would like to run (your options are 1-18 and\n"
            "all). You can specify several options by separating them by spaces."
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
        } else if (std::strcmp(argv[i], "9") == 0) {
            test9();
        } else if (std::strcmp(argv[i], "10") == 0) {
            test10();
        } else if (std::strcmp(argv[i], "11") == 0) {
            test11();
        } else if (std::strcmp(argv[i], "12") == 0) {
            test12();
        } else if (std::strcmp(argv[i], "13") == 0) {
            test13();
        } else if (std::strcmp(argv[i], "14") == 0) {
            test14();
        } else if (std::strcmp(argv[i], "15") == 0) {
            test15();
        } else if (std::strcmp(argv[i], "16") == 0) {
            test16();
        } else if (std::strcmp(argv[i], "17") == 0) {
            test17();
        } else if (std::strcmp(argv[i], "18") == 0) {
            test18();
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
            std::cout << std::endl;

            test9();
            std::cout << std::endl;

            test10();
            std::cout << std::endl;

            test11();
            std::cout << std::endl;

            test12();
            std::cout << std::endl;

            test13();
            std::cout << std::endl;

            test14();
            std::cout << std::endl;

            test15();
            std::cout << std::endl;

            test16();
            std::cout << std::endl;

            test17();
            std::cout << std::endl;

            test18();
        } else {
            std::cerr << argv[i] << " isn't a valid option (1-18 or all)" << std::endl;
        }

        if (i + 1 != argc) {
            std::cout << std::endl;
        }
    }

    return 0;
}
