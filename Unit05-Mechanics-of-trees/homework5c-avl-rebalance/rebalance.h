#pragma once

struct Node {
    Node* left;
    Node* right;
    int value;
    int height;

    Node(int v) : left(nullptr), right(nullptr), value(v), height(1) {}
};

// Hint: you might find it helpful to write an update_height function that takes
// a Node* and updates its height field based on the heights of its children

void promote_left(Node*& root) {
    // implement promote_left here
}

void promote_right(Node*& root) {
    // implement promote_right here
}

void rebalance(Node*& root) {
    // implement rebalance here
}
