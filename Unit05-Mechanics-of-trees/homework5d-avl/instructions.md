# HW 5d

## AVL Tree

Implement an AVL (Adelson-Velsky and Landis) Tree in the header file `AVL.h`. 

AVL Tree is a self-balancing Binary Search Tree (BST) where the difference of heights of left and right subtrees cannot be more than one for all nodes.

- Implement the following methods:
  - `const Node* getRootNode() const`: Returns the root of the tree (set to `nullptr` for an empty tree).
  - `bool insert(T item)`: Inserts an item and returns `true` if the item was inserted, `false` otherwise. The tree should remain balanced after the insertion.
  - `bool remove(T item)`: Removes an item, returns `true` if the item was removed, and `false` otherwise. The tree should remain balanced after the removal.
  - `bool contains(T item) const`: Returns `true` if the item is in the tree, `false` otherwise. This method should not modify the tree.
  - `void clear()`: Removes all nodes from the tree and resets its size.
  - `int size() const`: Returns the number of elements in the tree.
- Your AVL Tree should use the `rebalance` logic implemented in [HW 5c - AVL Rebalance](../homework5c-avl-rebalance/instructions.md)
  
## Grading

`AVL.h` is worth 100 points.
