# HW 5c

## AVL Tree Rebalancing

In this assignment, you will write an AVL tree rebalancing function in `rebalance.h`.

- The `Node` struct is provided for you
- Implement the following functions:
  - `void promote_left(Node*& root)`
  - `void promote_right(Node*& root)`
  - `void rebalance(Node*& root)`
    - If the height difference between the left and the right subtree is greater than 1 or less than -1, perform the required rotations
- Make sure to fully implement the AVL tree rotations correctly

**Note**

In the tests, the nodes are printed `<value>|<height>`.

## Grading

`rebalance.h` is worth 100 points.