#include <algorithm>
#include <cstring>
#include <initializer_list>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "rebalance.h"
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
        if (flat_tree[i] == nullptr) {
            continue;
        }
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

    // then give them heights
    for (size_t i = flat_tree.size(); i > 0;) {
        i -= 1;

        if (flat_tree[i] == nullptr) {
            continue;
        }

        int left_height;
        size_t left_index = 2 * i + 1;
        if (left_index < flat_tree.size()) {
            left_height = (flat_tree[left_index] == nullptr) ? 0 : flat_tree[left_index]->height;
        } else {
            left_height = 0;
        }

        int right_height;
        size_t right_index = 2 * i + 2;
        if (right_index < flat_tree.size()) {
            right_height = (flat_tree[right_index] == nullptr) ? 0 : flat_tree[right_index]->height;
        } else {
            right_height = 0;
        }

        flat_tree[i]->height = std::max(left_height, right_height) + 1;
    }

    if (flat_tree.empty()) {
        return nullptr;
    } else {
        return flat_tree[0];
    }
}

void noisy_promote_left(Node*& root) {
    promote_left(root);
    std::cout << "promote_left(root)" << std::endl;
}

void noisy_promote_right(Node*& root) {
    promote_right(root);
    std::cout << "promote_right(root)" << std::endl;
}

void noisy_rebalance(Node*& root) {
    rebalance(root);
    std::cout << "rebalance(root)" << std::endl;
}

// --------- END HELPER FUNCTIONS --------- 

// Checks that promote_left works with two nodes in the tree
void test1() {
    std::cout << "--- Test 1 output ---\n" << std::endl;

    Node* root = build_tree({ 2, 1 });
    pretty_print_tree(root);

    std::cout << std::endl;
    noisy_promote_left(root);

    std::cout << std::endl;
    pretty_print_tree(root);
}

// Checks that promote_left works with a bigger tree
void test2() {
    std::cout << "--- Test 2 output ---\n" << std::endl;

    Node* root = build_tree({ 6, 3, 8, 1, 4, 7, -1, -1, 2, -1, 5 });
    pretty_print_tree(root);

    std::cout << std::endl;
    noisy_promote_left(root);

    std::cout << std::endl;
    pretty_print_tree(root);
}

// Checks that promote_right works with two nodes in the tree
void test3() {
    std::cout << "--- Test 3 output ---\n" << std::endl;

    Node* root = build_tree({ 1, -1, 2 });
    pretty_print_tree(root);

    std::cout << std::endl;
    noisy_promote_right(root);

    std::cout << std::endl;
    pretty_print_tree(root);
}

// Checks that promote_right works with a bigger tree
void test4() {
    std::cout << "--- Test 4 output ---\n" << std::endl;

    Node* root = build_tree({ 3, 1, 6, -1, 2, 4, 8, -1, -1, -1, -1, -1, 5, 7 });
    pretty_print_tree(root);

    std::cout << std::endl;
    noisy_promote_right(root);

    std::cout << std::endl;
    pretty_print_tree(root);
}

// Checks that rebalance works with a leaf node
void test5() {
    std::cout << "--- Test 5 output ---\n" << std::endl;

    Node* root = build_tree({ 3 });
    pretty_print_tree(root);

    std::cout << std::endl;
    noisy_rebalance(root);

    std::cout << std::endl;
    pretty_print_tree(root);
}

// Checks that rebalance works with a balanced tree
void test6() {
    std::cout << "--- Test 6 output ---\n" << std::endl;

    Node* root = build_tree({ 5, 3, 8, 2, -1, 6, 9 });
    pretty_print_tree(root);

    std::cout << std::endl;
    noisy_rebalance(root);

    std::cout << std::endl;
    pretty_print_tree(root);
}

// Checks that rebalance works with a LL imbalance
void test7() {
    std::cout << "--- Test 7 output ---\n" << std::endl;

    Node* root = build_tree({ 5, 3, 6, 1, 4, -1, -1, -1, 2 });
    pretty_print_tree(root);

    std::cout << std::endl;
    noisy_rebalance(root);

    std::cout << std::endl;
    pretty_print_tree(root);
}

// Checks that rebalance works with a RR imbalance
void test8() {
    std::cout << "--- Test 8 output ---\n" << std::endl;

    Node* root = build_tree({ 2, 1, 4, -1, -1, 3, 6, -1, -1, -1, -1, -1, -1, 5 });
    pretty_print_tree(root);

    std::cout << std::endl;
    noisy_rebalance(root);

    std::cout << std::endl;
    pretty_print_tree(root);
}

// Checks that rebalance works with a LR imbalance
void test9() {
    std::cout << "--- Test 9 output ---\n" << std::endl;

    Node* root = build_tree({ 5, 2, 6, 1, 3, -1, -1, -1, -1, -1, 4 });
    pretty_print_tree(root);

    std::cout << std::endl;
    noisy_rebalance(root);

    std::cout << std::endl;
    pretty_print_tree(root);
}

// Checks that rebalance works with a RL imbalance
void test10() {
    std::cout << "--- Test 10 output ---\n" << std::endl;

    Node* root = build_tree({ 2, 1, 5, -1, -1, 4, 6, -1, -1, -1, -1, 3 });
    pretty_print_tree(root);

    std::cout << std::endl;
    noisy_rebalance(root);

    std::cout << std::endl;
    pretty_print_tree(root);
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
