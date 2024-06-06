#pragma once

#include <cmath>
using std::abs;

#include <algorithm>
using std::max;

template <class T>
class AVL
{
public:
    struct Node
    {
        Node *left;
        Node *right;
        T value;
        size_t height;

        Node(T v) : left(nullptr), right(nullptr), value(v), height(1) {}
    };

private:
    Node *_root;
    size_t _size;

    size_t _get_height(Node *const &node)
    {
        return (!node) ? 0 : node->height;
    }

    void _update_height(Node *&node)
    {
        node->height = 1 + max(_get_height(node->left), _get_height(node->right));
    }

    int _get_balance(Node *const &node)
    {
        return _get_height(node->right) - _get_height(node->left);
    }

    void _promote_left_child(Node *&node)
    {
        Node *new_root = node->left;
        node->left = new_root->right;
        new_root->right = node;
        node = new_root;

        _update_height(node->right);
        _update_height(node);
    }

    void _promote_right_child(Node *&node)
    {
        Node *new_root = node->right;
        node->right = new_root->left;
        new_root->left = node;
        node = new_root;

        _update_height(node->left);
        _update_height(node);
    }

    void _rebalance_right(Node *&node)
    {
        if (_get_balance(node->right) < 0)
        {
            _promote_left_child(node->right);
        }

        _promote_right_child(node);
    }

    void _rebalance_left(Node *&node)
    {
        if (_get_balance(node->left) > 0)
        {
            _promote_right_child(node->left);
        }

        _promote_left_child(node);
    }

    void _maybe_rebalance(Node *&node)
    {
        int balance = _get_balance(node);

        if (balance > 1)
        {
            _rebalance_right(node);
        }
        else if (balance < -1)
        {
            _rebalance_left(node);
        }
    }

    bool _insert(Node *&node, T const &item)
    {
        if (node == nullptr)
        {
            node = new Node(item);
            _size++;
            return true;
        }

        if (node->value == item)
        {
            return false;
        }

        Node *&which = (item < node->value) ? node->left : node->right;
        bool ret = _insert(which, item);
        _update_height(node);
        _maybe_rebalance(node);
        return ret;
    }

    bool _contains(Node *const&node, T const &item) const
    {
        if (!node)
        {
            return false;
        }

        if (item == node->value)
        {
            return true;
        }

        if (item < node->value)
        {
            return _contains(node->left, item);
        }
        else
        {
            return _contains(node->right, item);
        }
    }

    void _clear(Node *&node)
    {
        if (!node)
        {
            return;
        }

        _clear(node->left);
        _clear(node->right);

        delete node;
        node = nullptr;
    }

    Node* _find_inorder_pred(Node* const& node) const {
        Node* iop = node->left;
        while (!iop->right) {
            iop = iop->right;
        }
        return iop;
    }

    bool _remove(Node*& node, T const& item) {
        if (!node) {
            return false;
        }

        Node* tmp = node;
        bool ret;
        if (item == node->value) {
            if (!node->right) {
                node = node->left;
                delete tmp;
            }
            else if (!node->left) {
                node = node->right;
                delete tmp;
            }
            else { // Two children
                Node* iop = _find_inorder_pred(node);
                node->value = iop->value;
                _remove(node->left, node->value);
            }
            ret = true;
        }
        else if (item < node->value) {
            ret = _remove(node->left, item);
        } else {
            ret = _remove(node->right, item);
        }

        _update_height(node);
        _maybe_rebalance(node);

        return ret;
    }

public:
    AVL() : _root(nullptr), _size(0) {}

    ~AVL()
    {
        clear();
    }

    const Node *getRootNode() const
    {
        return _root;
    }

    bool insert(T item)
    {
        return _insert(_root, item);
    }

    bool remove(T item)
    {
        return _remove(_root, item);
    }

    bool contains(T item) const
    {
        return _contains(_root, item);
    }

    void clear()
    {
        _clear(_root);
        _size = 0;
    }

    int size() const
    {
        return _size;
    }
};
