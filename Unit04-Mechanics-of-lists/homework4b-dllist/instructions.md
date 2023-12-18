# HW 4b

## Double Linked List

Write a Double Linked List class in `DLList.h`. The class should be templated on the type of objects it can store.

- Implement a struct for `Node`, with members: 
    * `prev` (a pointer to the previous node)
    * `next` (a pointer to the next node)
    * `value` (the object to store in the node)
- Implement a class for the Double Linked List (DLList), with the following methods:
  - `DLList()`
  - `~DLList()`: destructor that clears the dllist
  - `const Node* get_head() const`: returns the `head` of the list
  - `void push_front(T item)`: inserts a node at the front (beginning) of the list
  - `void push_back(T item)`: inserts a node at the back (end) of the list
  - `void insert(T item, int position)`: inserts a node at the index of `position`
  - `void pop_front()`: remove a node at the front (beginning) of the list
  - `void pop_back()`: remove a node at the back (end) of the list
  - `void remove(int position)`: remove the node at the index of `position`
  - `const T& front() const`: returns the `value` of the node at the front of the list
  - `const T& back() const`: returns the `value` of the node at the back of the list
  - `const T& at(int index) const`: returns the `value` of the node at the given `index`
  - `bool contains(const T& item) const`: checks of the list contains a node with the given value (`item`)
  - `int size() const`: returns the current size of the list
  - `void clear()`: deletes every node in the list
- Implement appropriate error handling
  - `front`, `back`, `pop_front`, and `pop_back` should throw an `std::length_error` if the list is empty
  - `insert`, `remove`, and `at` should throw an `std::out_of_range` if the index is out of range

## Using provided tests.cpp file

The following example will run the first automatic test:
```
g++ tests.cpp -o tests
./tests 1
```
**The possible tests for this assignment are 1, 2, 3, 4, 5, 6, 7, 8, or all.**

### A guide to what new functions each of the tests call:
* Test 1: `push_front()` and `push_back()`
* Test 2: `insert()`
* Test 3: `front()` and `back()`
* Test 4: `at()`
* Test 5: `contains()`
* Test 6: `pop_front()` and `pop_back()`
* Test 7: `remove()`
* Test 8: `size()` and `clear()`
* all: runs tests 1-8

## Grading

`DLList.h` is worth 100 points.