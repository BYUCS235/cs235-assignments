#include <cstring>
#include <initializer_list>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "find.h"
#include "printing.h"

// --------- HELPER FUNCTIONS --------- 

Node* build_tree(std::initializer_list<int> flat_tree_vals) {
    std::vector<Node*> flat_tree;
    flat_tree.reserve(flat_tree_vals.size());

    // create nodes
    for (int val : flat_tree_vals) {
        if (val >= 0) {
            flat_tree.push_back(new Node(val));
        } else {
            flat_tree.push_back(nullptr);
        }
    }

    // then wire them up
    for (size_t i = 1; i < flat_tree.size(); i++) {
        if (flat_tree[i] != nullptr) {
            size_t parent_idx = (i - 1) / 2;

            if (flat_tree[parent_idx] == nullptr) {
                std::stringstream ss;
                ss << "value at index " << i << " has a null parent";
                throw std::logic_error(ss.str());
            }

            // odd index represents a left child
            if (i % 2 == 1) {
                flat_tree[parent_idx]->left = flat_tree[i];
            }
            // and even index represents a right child
            else {
                flat_tree[parent_idx]->right = flat_tree[i];
            }
        }
    }

    if (flat_tree.empty()) {
        return nullptr;
    } else {
        return flat_tree[0];
    }
}

void noisy_find(Node* root, int item) {
    std::cout << "find(root, " << item << ") = " << std::boolalpha << find(root, item) << std::endl;
}

// --------- END HELPER FUNCTIONS --------- 

// Checks that find works with an empty tree
void test1() {
    std::cout << "--- Test 1 output ---\n" << std::endl;

    Node* tree = build_tree({});

    pretty_print_tree(tree);
    std::cout << std::endl;

    noisy_find(tree, 1);
    noisy_find(tree, 2);
    noisy_find(tree, 3);
    noisy_find(tree, 4);
    noisy_find(tree, 5);
    noisy_find(tree, 6);
    noisy_find(tree, 7);
    noisy_find(tree, 8);
    noisy_find(tree, 9);
    noisy_find(tree, 10);
}

// Checks that find works with a single line to the right
void test2() {
    std::cout << "--- Test 2 output ---\n" << std::endl;

    Node* tree = build_tree({ 2, -1, 3, -1, -1, -1, 6, -1, -1, -1, -1, -1, -1, -1, 8 });

    pretty_print_tree(tree);
    std::cout << std::endl;

    noisy_find(tree, 1);
    noisy_find(tree, 2);
    noisy_find(tree, 3);
    noisy_find(tree, 4);
    noisy_find(tree, 5);
    noisy_find(tree, 6);
    noisy_find(tree, 7);
    noisy_find(tree, 8);
    noisy_find(tree, 9);
    noisy_find(tree, 10);
}

// Checks that find works with a single line to the left
void test3() {
    std::cout << "--- Test 3 output ---\n" << std::endl;

    Node* tree = build_tree({ 10, 7, -1, 6, -1, -1, -1, 2 });

    pretty_print_tree(tree);
    std::cout << std::endl;

    noisy_find(tree, 1);
    noisy_find(tree, 2);
    noisy_find(tree, 3);
    noisy_find(tree, 4);
    noisy_find(tree, 5);
    noisy_find(tree, 6);
    noisy_find(tree, 7);
    noisy_find(tree, 8);
    noisy_find(tree, 9);
    noisy_find(tree, 10);
}

// Checks that find works with a balanced tree
void test4() {
    std::cout << "--- Test 4 output ---\n" << std::endl;

    Node* tree = build_tree({ 5, 3, 8, 2, -1, 6, 9 });

    pretty_print_tree(tree);
    std::cout << std::endl;

    noisy_find(tree, 1);
    noisy_find(tree, 2);
    noisy_find(tree, 3);
    noisy_find(tree, 4);
    noisy_find(tree, 5);
    noisy_find(tree, 6);
    noisy_find(tree, 7);
    noisy_find(tree, 8);
    noisy_find(tree, 9);
    noisy_find(tree, 10);
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
