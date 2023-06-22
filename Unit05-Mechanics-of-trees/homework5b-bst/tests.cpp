#include <cstring>
#include <iostream>
#include <string>

#include "BST.h"
#include "printing.h"

// --------- HELPER FUNCTIONS --------- 

void noisy_insert(BST<int>& tree, int item) {
    std::cout << "tree.insert(" << item << ") = " << std::boolalpha << tree.insert(item) << std::endl;
}

void noisy_remove(BST<int>& tree, int item) {
    std::cout << "tree.remove(" << item << ") = " << std::boolalpha << tree.remove(item) << std::endl;
}

void noisy_contains(const BST<int>& tree, int item) {
    std::cout << "tree.contains(" << item << ") = " << std::boolalpha << tree.contains(item) << std::endl;
}

void noisy_clear(BST<int>& tree) {
    tree.clear();
    std::cout << "tree.clear()" << std::endl;
}

void noisy_size(const BST<int>& tree) {
    std::cout << "tree.size() = " << tree.size() << std::endl;
}

// --------- END HELPER FUNCTIONS --------- 

// Checks that insert works to build a simple tree
void test1() {
    std::cout << "--- Test 1 output ---\n" << std::endl;

    BST<int> tree;

    noisy_insert(tree, 2);
    noisy_insert(tree, 1);
    noisy_insert(tree, 3);

    std::cout << std::endl;
    pretty_print_tree(tree);

    std::cout << std::endl;
    noisy_insert(tree, 1);
    noisy_insert(tree, 2);
    noisy_insert(tree, 3);
}

// Checks that insert works to build up a more complex tree
void test2() {
    std::cout << "--- Test 2 output ---\n" << std::endl;

    BST<int> tree;

    noisy_insert(tree, 9);
    noisy_insert(tree, 5);
    noisy_insert(tree, 2);
    noisy_insert(tree, 4);
    noisy_insert(tree, 3);
    noisy_insert(tree, 11);
    noisy_insert(tree, 10);
    noisy_insert(tree, 12);

    std::cout << std::endl;
    pretty_print_tree(tree);
}

// Checks that remove works with a leaf node
void test3() {
    std::cout << "--- Test 3 output ---\n" << std::endl;

    BST<int> tree;

    tree.insert(2);
    tree.insert(1);
    tree.insert(3);

    pretty_print_tree(tree);

    std::cout << std::endl;
    noisy_remove(tree, 1);

    std::cout << std::endl;
    pretty_print_tree(tree);

    std::cout << std::endl;
    noisy_remove(tree, 1);
}

// Checks that remove works with a node that only has a left child
void test4() {
    std::cout << "--- Test 4 output ---\n" << std::endl;

    BST<int> tree;

    tree.insert(2);
    tree.insert(1);

    pretty_print_tree(tree);

    std::cout << std::endl;
    noisy_remove(tree, 2);

    std::cout << std::endl;
    pretty_print_tree(tree);
}

// Checks that remove works with a node that only has a right child
void test5() {
    std::cout << "--- Test 5 output ---\n" << std::endl;

    BST<int> tree;

    tree.insert(1);
    tree.insert(2);

    pretty_print_tree(tree);

    std::cout << std::endl;
    noisy_remove(tree, 1);

    std::cout << std::endl;
    pretty_print_tree(tree);
}

// Checks that remove works with a node that has two children where the inorder
// predecessor is the node's left child
void test6() {
    std::cout << "--- Test 6 output ---\n" << std::endl;

    BST<int> tree;

    tree.insert(2);
    tree.insert(1);
    tree.insert(3);

    pretty_print_tree(tree);

    std::cout << std::endl;
    noisy_remove(tree, 2);

    std::cout << std::endl;
    pretty_print_tree(tree);
}

// Checks that remove works with a node that has two children where the node's
// left child has a right subtree
void test7() {
    std::cout << "--- Test 7 output ---\n" << std::endl;

    BST<int> tree;

    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);

    pretty_print_tree(tree);

    std::cout << std::endl;
    noisy_remove(tree, 4);

    std::cout << std::endl;
    pretty_print_tree(tree);
}

// Checks that remove works by repeatedly removing the root node until the tree
// is empty
void test8() {
    std::cout << "--- Test 8 output ---\n" << std::endl;

    BST<int> tree;

    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);

    pretty_print_tree(tree);

    std::cout << std::endl;
    noisy_remove(tree, 4);
    noisy_remove(tree, 3);
    noisy_remove(tree, 2);
    noisy_remove(tree, 1);
    noisy_remove(tree, 6);
    noisy_remove(tree, 5);
    noisy_remove(tree, 7);

    std::cout << std::endl;
    pretty_print_tree(tree);
}

// Checks that contains works
void test9() {
    std::cout << "--- Test 9 output ---\n" << std::endl;

    BST<int> tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(8);
    tree.insert(2);
    tree.insert(6);
    tree.insert(9);

    pretty_print_tree(tree);

    std::cout << std::endl;

    noisy_contains(tree, 1);
    noisy_contains(tree, 2);
    noisy_contains(tree, 3);
    noisy_contains(tree, 4);
    noisy_contains(tree, 5);
    noisy_contains(tree, 6);
    noisy_contains(tree, 7);
    noisy_contains(tree, 8);
    noisy_contains(tree, 9);
    noisy_contains(tree, 10);
}

// Checks that size and clear work
void test10() {
    std::cout << "--- Test 10 output ---\n" << std::endl;

    BST<int> tree;

    noisy_size(tree);
    noisy_insert(tree, 3);
    noisy_size(tree);
    noisy_insert(tree, 3);
    noisy_size(tree);

    std::cout << std::endl;
    noisy_remove(tree, 3);
    noisy_size(tree);
    noisy_remove(tree, 3);
    noisy_size(tree);

    std::cout << std::endl;
    noisy_insert(tree, 4);
    noisy_insert(tree, 6);
    noisy_insert(tree, 7);
    noisy_insert(tree, 1);
    noisy_size(tree);

    std::cout << std::endl;
    noisy_clear(tree);
    noisy_size(tree);

    std::cout << std::endl;
    noisy_insert(tree, 7);
    noisy_insert(tree, 9);
    noisy_size(tree);
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        std::cerr << "You must specify which tests you would like to run (your options are 1, 2, 3, 4, 5, 6,\n"
            "7, 8, 9, 10 and all). You can specify several options by separating them by spaces."
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
        } else {
            std::cerr << argv[i] << " isn't a valid option (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, or all)" << std::endl;
        }

        if (i + 1 != argc) {
            std::cout << std::endl;
        }
    }

    return 0;
}
