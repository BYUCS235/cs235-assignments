#pragma once

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>

#include "BST.h"

// A whole bunch of helper functions come below. You don't need to think about
// them unless you want to read them for fun!

// --------------------   HELPER FUNCTIONS   --------------------

void ugly_print_tree_helper(const BST<int>::Node* node) {
    if (node == nullptr) {
        return;
    }
    const BST<int>::Node* left = node->left;
    const BST<int>::Node* right = node->right;
    std::cout << node->value << ": ";
    if (left == nullptr) {
        std::cout << "__";
    } else {
        std::cout << left->value;
    }
    std::cout << ' ';
    if (right == nullptr) {
        std::cout << "__";
    } else {
        std::cout << right->value;
    }
    std::cout << std::endl;

    ugly_print_tree_helper(left);
    ugly_print_tree_helper(right);
}

int tree_height(const BST<int>::Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return std::max(tree_height(node->left), tree_height(node->right)) + 1;
}

constexpr int num_spaces_for_level(int height, int level) {
    return (1 << (height - level + 1)) - 2;
}

constexpr int num_nodes_in_level(int level) {
    return 1 << level;
}

void print_spaces(int quantity) {
    for (int i = 0; i < quantity; ++i) {
        std::cout << ' ';
    }
}

// -------------------- END HELPER FUNCTIONS --------------------

// You don't need to understand the following function (unless you want to read
// it for fun!). All you need to know is that you can use it to print out your
// tree. The advantage of this function over `ugly_print_tree` is that the
// resulting printout is easier to read since it's in a tree-like shape. For
// instance, if `tree` has the following structure:
//
//        15
//       /  \
//      /    \
//    13      17
//   /       /  \
// 12      16    18
//
// then `pretty_print_tree(tree)` will output the following:
//
//       15
// 
//   13      17
// 
// 12      16  18
//
// The disadvantages of this function are:
//   1) The width of the printout explodes as the tree gets taller. For
//      instance, the printout of a tree with height 6 will be about 125
//      characters wide, and the width about doubles with each additional level.
//   2) The function is only written to deal with numbers that have at most 2
//      digits.
//
// If you need to visualize a tree that is either taller or has bigger numbers,
// look at `ugly_print_tree`, which is under `pretty_print_tree`. Its printout
// is a bit harder to read, but can work for bigger trees.
void pretty_print_tree(const BST<int>& tree) {
    const BST<int>::Node* root = tree.getRootNode();
    if (root == nullptr) {
        std::cout << "Empty tree" << std::endl;
        return;
    }

    std::queue<const BST<int>::Node*> traversal;
    traversal.push(root);

    int height = tree_height(root);
    for (int level = 0; level < height; ++level) {
        int spaces_in_between = num_spaces_for_level(height, level);
        int spaces_before = spaces_in_between / 2 - 1;
        print_spaces(spaces_before);

        int nodes = num_nodes_in_level(level);
        bool print_spaces_before = false;
        for (int ni = 0; ni < nodes; ++ni) {
            if (print_spaces_before) {
                print_spaces(spaces_in_between);
            }
            print_spaces_before = true;

            const BST<int>::Node* node = traversal.front();
            traversal.pop();

            if (node == nullptr) {
                std::cout << "  ";
                traversal.push(nullptr);
                traversal.push(nullptr);
            } else {
                std::cout << std::setw(2) << std::right << std::setfill(' ') << node->value;
                traversal.push(node->left);
                traversal.push(node->right);
            }
        }
        if (level != height - 1) {
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

// You don't need to understand the following function (unless you want to read
// it for fun!). All you need to know is that you can use it to print out your
// tree. The advantages of this function over `pretty_print_tree` is that the
// resulting printout doesn't explode in width as the height of the tree
// increases and it can handle numbers with more than 2 digits. The disadvantage
// is that `ugly_print_tree`'s printout is harder to read than
// `pretty_print_tree`'s. For instance, if `tree` has the following structure:
//
//        15
//       /  \
//      /    \
//    13      17
//   /       /  \
// 12      16    18
//
// then `ugly_print_tree(tree)` will output the following:
//
// 15: 13 17
// 13: 12 __
// 12: __ __
// 17: 16 18
// 16: __ __
// 18: __ __
//
// If you need to visualize a tree that is shorter and has small enough numbers,
// you could also use `pretty_print_tree`, which is above. Its printout can be
// easier to read if the tree is not too tall and doesn't have too big of
// numbers.
void ugly_print_tree(const BST<int>& tree) {
    const BST<int>::Node* root = tree.getRootNode();
    if (root == nullptr) {
        std::cout << "Empty tree" << std::endl;
    } else {
        ugly_print_tree_helper(root);
    }
}