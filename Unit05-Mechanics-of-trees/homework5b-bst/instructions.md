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
- Bear in mind that you are allowed and expected to create your own helper functions to complete this assignment.

## Using provided tests.cpp file

The following example will run the first automatic test:
```
$ g++ tests.cpp -o tests
$ ./tests 1
```

**The possible tests for this assignment are 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, or all.**

### A guide to what new functions each of the tests call:
* Test 1: `insert()` for a simple tree
* Test 2: `insert()` for a complex tree
* Test 3: `remove()` a leaf node
* Test 4: `remove()` a node that only has a left child
* Test 5: `remove()` a node that only has a right child
* Test 6: `remove()` a node that has two children and the iop is the left child
* Test 7: `remove()` a node with two children where node's left child has a right subtree
* Test 8: `remove()` the root node repeatedly until the tree is empty
* Test 9: `contains()`
* Test 10: `size()` and `clear()`
* all: runs tests 1-10

## Grading

`BST.h` is worth 100 points.

| Methods                            | Points  |
|------------------------------------|---------|
| insert into empty tree             | 10      |
| build complex tree                 | 10      |
| remove leaf node                   | 10      |
| remove node with left child        | 10      |
| remove node with right child       | 10      |
| remove node with two leaf children | 10      |
| remove node with two subtrees      | 10      |
| repeatedly remove root             | 10      |
| contains                           | 10      |
| size & clear                       | 10      |
| **Total**                          | **100** |