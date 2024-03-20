# HW 5a

## Binary Search Tree Find

Write a function to perform a search in a binary search tree in `find.h`.

- The struct `Node` for the binary search tree nodes is provided
- Implement the function `bool find(Node* root, int item)` for searching a value in the tree
  - The function takes a pointer to the root of the subtree, and an integer `item` to search for
  - The function returns `true` if the item is found, or `false` otherwise
- Assume the tree is a valid binary search tree


## Using provided tests.cpp file

The following example will run the first automatic test:
```
g++ tests.cpp -o tests
./tests 1
```
**The possible tests for this assignment are 1, 2, 3, 4, or all.**

### A guide to what new functions each of the tests call:
* Test 1: `find()` on an empty tree
* Test 2: `find()` on a tree with a single right child
* Test 3: `find()` on a tree with a single left child
* Test 4: `find()` on a balanced tree
* all: runs tests 1-4

## Grading

`find.h` is worth 100 points.

| Methods          | Points   |
|------------------|----------|
| empty tree       | 25       |
| line going right | 25       |
| line going left  | 25       |
| balanced tree    | 25       |
| **Total**        | **100**  |