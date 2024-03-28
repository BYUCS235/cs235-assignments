#pragma once

#include <cmath> 
using std::abs;

template<class T>
class AVL {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;
        size_t height;

        Node(T v) : left(nullptr), right(nullptr), value(v), height(1) {}
    };

private:
    Node* _root;
    size_t _size;

    int _get_height(Node* const& node) {
        if (node == nullptr) { return 0; }
        return node->height;
    }

    int _get_balance(Node* const& node) {
        return _get_height(node->right) - _get_height(node->left);
    }
    
    void _update_height(Node*& node) {
        size_t right_h = _get_height(node->right);
        size_t left_h = _get_height(node->left);
        node->height = ((right_h > left_h) ? right_h : left_h) + 1;
    }

    void _promote_left(Node*& node) {
        Node* new_root = node->left;
        node->left = new_root->right;
        new_root->right = node;
        node = new_root;
        _update_height(node->right);
        _update_height(node);
    }

    void _promote_right(Node*& node) {
        Node* new_root = node->right;
        node->right = new_root->left;
        new_root->left = node;
        node = new_root;
        _update_height(node->left);
        _update_height(node);
    }

    void _check_and_maybe_fix_balance(Node*& node) {
        if (_get_balance(node) < -1) {
            // Left imbalance
            if (_get_balance(node->left) > 0) {
                // Left right imbalance
                _promote_right(node->left);
            }
            _promote_left(node);
        }

        if (_get_balance(node) > 1) {
            // right imbalance
            if (_get_balance(node->right) < 0) {
                // right left imbalance
                _promote_left(node->right);
            }
            _promote_right(node);
        }
    }

    bool _insert(Node*& node, T const& item) {
        if (node == nullptr) {
            node = new Node(item);
            _size++;
            return true;
        }

        if (node->value == item) {
            return false;
        }

        bool added = false;
        if (item < node->value) {
            bool added =  _insert(node->left, item);
            
        } else {
            bool added = _insert(node->right, item);    
        }

        if (added) {
            _update_height(node);
            _check_and_maybe_fix_balance(node);
        }

        return added;
    }

public:
    AVL() {
        // implement the contructor here
    }

    ~AVL() {
        // implement the destructor here
    }

    const Node* getRootNode() const {
        return _root;
    }

    bool insert(T item) {
        return _insert(_root, item);
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
