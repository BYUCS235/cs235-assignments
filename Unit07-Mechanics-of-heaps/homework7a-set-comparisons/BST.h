#pragma once

template<class T>
class BST {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;

        Node(T v) : left(nullptr), right(nullptr), value(v) {}
    };

    BST() {
        // implement the contructor here
    }

    ~BST() {
        // implement the destructor here
    }

    const Node* getRootNode() const {
        // implement getRootNode here
        // return a pointer to the tree's root node
    }

    bool insert(T item) {
        // implement insert here
        // return true if item was inserted, false if item was already in the tree
    }

    bool remove(T item) {
        // implement remove here
        // return true if item was removed, false if item wasn't in the tree
    }

    bool contains(T item) const {
        // implement contains here
        // return true if item is in the tree, false otherwise
    }

    void clear() {
        // implement clear here
        // remove all nodes from the tree
    }

    int size() const {
        // implement size here
        // return the number of nodes in the tree
    }
};
