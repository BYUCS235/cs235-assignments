# HW 4d

## Vector Iterator

Implement a simple dynamically-allocated array in `Vector.h` with support for *for-each* syntax.

In addition to the functionality described in [HW 4c Vector](../homework4c-vector/instructions.md), this submission should:

- Implement `begin()` and `end()` that return `Iterator` objects for the first and one past the last elements respectively
- Implement the `Iterator` class with 
  - `operator*()` - retrieve the value of the current item
  - `operator++()` - advance to the next item
  - `operator==()` - return true if the current iterator and the `other` iterator are equal
  - `operator!=()` - return the opposite of `operator==()`
- You can keep track of the current item using a private class variable for the Iterator class. Here's how you declare it: `T* currItem;`

**HINTS**
* For a short overview on how C++ iterators work, see this [video](https://youtu.be/EgVWWVZ6AEY?si=E6OW03gKQWDeylRo).
* Retrieving the value a pointer points at is called "de-referencing" the pointer. De-referencing a pointer will give you a `T&` type.
* You can advance pointers to the next memory address using `++`
* A pointer to the current Iterator-type object you're using will be stored in `this`. You can retrieve the value of `this` (the value being an `Iterator&` type) by dereferencing it.


## Using provided tests.cpp file

The following example will run the first automatic test:
```
g++ tests.cpp -o tests
./tests 1
```
**The possible tests for this assignment are 1, 2, or all.**

### A guide to what new functions each of the tests call:
* Test 1: `push_back(), begin(), end(), ==, !=, ++`
* Test 2: `*`
* all: runs tests 1-2

**Grading**

`Vector.h` is worth 100 points.
