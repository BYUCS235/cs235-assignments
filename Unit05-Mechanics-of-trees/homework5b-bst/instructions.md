# HW 5b

## Binary Search Tree

Implement a binary search tree in `BST.h`. The class should be templated to accept any data type.

- The `Node` struct with members `left`, `right`, and `value` is provided for you.
- Implement the following methods for the `BST` class:
  - `BST()` - Should properly allocate an empty tree.
  - `~BST()` - Should properly clear the tree.
  - `insert(T item)` - Inserts a new node with the given value. Returns true if insertion is successful, false if the item already exists in the tree.
  - `remove(T item)` - Removes a node containing the given value. Returns true if removal is successful, false if the item does not exist in the tree.
  - `contains(T item)` - Returns true if the item is found in the tree, false otherwise.
  - `getRootNode()` - Returns the root of the tree (set to `nullptr` for an empty tree).
  - `clear()` - Removes all nodes from the tree.
  - `size()` - Returns the number of nodes in the tree.

## Grading

`BST.h` is worth 100 points.