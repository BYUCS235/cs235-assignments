# HW 4d

## Vector Iterator

Implement a simple dynamically-allocated array (i.e. the `vector`) in `Vector.h` with support for *for-each* syntax.

In addition to the functionality described in [HW 4c Vector](../homework4c-vector/instructions.md), this submission should:

- Implement `begin()` and `end()` that return `Iterator` objects for the first and one past the last elements respectively
- Implement the `Iterator` class with 
  - `operator*()` - retrieve the value of the current item
  - `operator++()` - advance to the next item
  - `operator==()` - return true if the current iterator and the `other` iterator are equal
  - `operator!=()` - return the opposite of `operator==()`
- You can keep track of the current item using a private class variable for the Iterator class. Here's how you declare it: `T* currItem;`

**Strategy**
* For a short overview on how C++ iterators work, see this [video](https://youtu.be/EgVWWVZ6AEY?si=E6OW03gKQWDeylRo).
* You want your `iterator` class to store a `T*`
  * This points to the current item in the vector
  * Because all the items in the vector are stored in contiguous memory (i.e. an array), we can increment the pointer to get to the next item.
* The `begin()` function in your vector class should return an iterator initialized to the first position in your array.
* The `end()` function in your vector class should return an interator initialized to the first position **after** your array (i.e. `array + len`).
  * When your iterator reaches this position, you know you are done iterating.
* `operator*` should return the value the current pointer is pointing to
  * Use the `*` operator on the `T*` pointer to get its value (i.e. a `T&`)
* `operator++` should make the current pointer advance to the next slot in memory
  * Remember, you can make a pointer advance to the next slot with the `++` operator
  * This operator is supposed to return an `iterator&`. Use `return *this;`.
* `operator==` and `operator!=` should compare whether the two iterators points to the same address
* Retrieving the value a pointer points at is called "de-referencing" the pointer. De-referencing a pointer of type `T*` will give you a `T&` type.


## Using provided tests.cpp file

The following example will run the first automatic test:
```
$ g++ tests.cpp -o tests
$ ./tests 1
```

**The possible tests for this assignment are 1, 2, or all.**

### A guide to what new functions each of the tests call:
* Test 1: `push_back(), begin(), end(), ==, !=, ++`
* Test 2: `*`
* all: runs tests 1-2

**Grading**

Your extended `Vector.h` (with iterator support) is worth 100 points.

| Methods                 | Points  |
| ----------------------- | ------- |
| iteration with `int`    | 50      |
| iteration with `string` | 50      |
| **Total**               | **100** |