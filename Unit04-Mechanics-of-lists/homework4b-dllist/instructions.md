# HW 4b

## Double Linked List

Write a Double Linked List class in `DLList.h`. The class should be templated on the type of objects it can store.

- Implement a struct for `Node`, with members: `prev` (previous node), `next` (next node), and `value` (the object to store in the node)
- Implement a class for the Double Linked List (DLList), with the following methods:
  - `DLList()`
  - `~DLList()`
  - `const Node* get_head() const`
  - `void push_front(T item)`
  - `void push_back(T item)`
  - `void insert(T item, int position)`
  - `void pop_front()`
  - `void pop_back()`
  - `void remove(int position)`
  - `const T& front() const`
  - `const T& back() const`
  - `const T& at(int index) const`
  - `bool contains(const T& item) const`
  - `int size() const`
  - `void clear()`
- Implement appropriate error handling
  - `front`, `back`, `pop_front`, and `pop_back` should throw an `std::length_error` if the list is empty
  - `insert`, `remove`, and `at` should throw an `std::out_of_range` if the index is out of range

## Grading

`DLList.h` is worth 100 points.