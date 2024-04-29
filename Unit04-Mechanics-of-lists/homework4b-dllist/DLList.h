#pragma once

#include <iostream>
#include <string>

template<class T>
class DLList {
public:
    // **Important**
    // Normally you would make the Node struct PRIVATE
    // but for this assignment it is important to keep it 
    // PUBLIC
    // Also, the declaration of Node needs to come 
    // before everything else in the class, so leave it here
    // at the beginning.
    struct Node {
        Node* prev;
        Node* next;
        T value;

        Node(T v) : prev(nullptr), next(nullptr), value(v) {}
    };

private:
    // Put your private fields/methods here

public:
    DLList() {}

    ~DLList() {}

    const Node* get_head() const {
        // implement get_head here
    }

    void push_front(T item) {
        // implement push_front here
    }
    void push_back(T item) {
        // implement push_back here
    }
    void insert(T item, int position) {
        // implement insert here
    }

    void pop_front() {
        // implement pop_front here
    }
    void pop_back() {
        // implement pop_back here
    }
    void remove(int position) {
        // implement remove here
    }

    const T& front() const {
        // implement front here
    }
    const T& back() const {
        // implement back here
    }
    const T& at(int index) const {
        // implement at here
    }

    bool contains(const T& item) const {
        // implement contains here
    }

    int size() const {
        // implement size here
    }

    void clear() {
        // implement clear here
    }
};
