#pragma once

struct Node {
    Node* left;
    Node* right;
    int value;

    Node(int v) : left(nullptr), right(nullptr), value(v) {}
};

bool find(Node* root, int item) {
    // implement find here
    // return true if item is in the subtree, false otherwise
}
