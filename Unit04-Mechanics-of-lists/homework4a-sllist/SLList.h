#pragma once
#include <cstddef>

template <class T>
class SLList {
public:
    struct Node {
        Node* next;
        T value;

        Node(T v) : next(nullptr), value(v) {}
    };

    SLList() {}

    ~SLList() {}

    const Node* get_head() const {
        // implement get_head here
    }

    void push_back(T item) {
        // implement push_back here
    }

    void pop_back() {
        // implement pop_back here
    }

    const T& front() const {
        // implement front here
    }

    size_t size() const {
        // implement size here
    }

    void clear() {
        // implement clear here
    }
};
