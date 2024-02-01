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

| Methods                      | Points   |
|------------------------------|----------|
| avl rebalance                | 5        |
| promote left with tree       | 7        |
| promote right with two nodes | 5        |
| promote right with tree      | 7        |
| rebalance leaf nodes         | 5        |
| rebalance balanced tree      | 5        |
| rebalance LL imbalance       | 15       |
| rebalance RR imbalance       | 15       |
| rebalance LR imbalance       | 18       |
| rebalance RL imbalance       | 18       |
| **Total**                    | **100**  |