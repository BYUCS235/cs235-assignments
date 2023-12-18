# HW 4a 

## Singly Linked List

Create a singly linked list template class `SLList` in `SLList.h`.

- Store elements of any data type using a template
- Define a struct named `Node` inside the `SLList` class with two members:
  - `next` - a pointer to the next `Node` in the list
  - `value` - an object of the data type to store the value of the node
- Provide the following member functions:
  - `SLList()` - a default constructor that initializes an empty list
  - `~SLList()` - a destructor that clears the list
  - `const Node* get_head() const` - returns a pointer to the head node
  - `void push_back(T item)` - adds a new node with the given `item` to the end of the list
  - `void pop_back()` - removes the last node in the list
  - `const T& front() const` - returns a const reference to the value of the head node (assume list is not empty)
  - `int size() const` - returns the current size of the list (i.e., the number of elements/nodes)
  - `void clear()` - removes all nodes from the list
- You can assume that `pop_back` and `front` will only be called when the list is not empty
- Do not use any existing C++ data structures (e.g., `std::list`, `std::vector`)

## Using provided tests.cpp file

The following example will run the first automatic test:
```
g++ tests.cpp -o tests
./tests 1
```
**The possible tests for this assignment are 1, 2, 3, 4, or all.**

### A guide to what new functions each of the tests call:
* Test 1: `push_back()`
* Test 2: `pop_back()`
* Test 3: `front()`
* Test 4: `size()` and `clear()`
* all: runs tests 1-4

## Grading

`SLList.h` is worth 100 points.