# HW 4c

## Vector Class

Create a `Vector` class in `Vector.h`.

- Implement a dynamic array-based vector class that can hold elements of any data type
- Include the following public member functions:
  - `Vector()`: The constructor for the class used for initializing private class variables
  - `~Vector()`: The destructor used to deallocate all `new`'d memory (hint: you'll be using `delete[]`)
  - `void push_back(T item)`: Append an item to the end of the vector
  - `void insert(T item, int position)`: Insert an item at a given position in the vector, shifting remaining elements to the right
  - `void remove(int position)`: Remove the item at the given position, shifting elements to the left. HINT: instead of trying to remove the item, think of overwriting it instead.
  - `T& operator[](int index)`: Access the item at the given index without bounds checking
  - `int size() const`: Return the number of elements in the vector
  - `void clear()`: Clear the vector, making it empty
- The class should automatically resize the array when necessary (we recommend doing this in a separate `grow()` function, though this is not required)
  - The capacity of the array should be **doubled** each time it is resized.
  - The contents of the old array should be copied into the resized array.
- `insert`, `remove`, and `operator[]` should throw an `std::out_of_range` exception if the index is out of range

**Notes**

* All tests will require `operator[]` and `size` to be implemented so that the vector can be printed.
* Make sure you use `capacity` and `size` correctly-- `capacity` refers to the maximum possible size of the array, `size` refers to the number of elements currently present in the array.


## Using provided tests.cpp file

The following example will run the first automatic test:
```
g++ tests.cpp -o tests
./tests 1
```
**The possible tests for this assignment are 1, 2, 3, 4, 5, 6, or all.**

### A guide to what new functions each of the tests call:
* Test 1: `push_back()`
* Test 2: `insert()`
* Test 3: `operator[]`
* Test 4: `remove()`
* Test 5: `size()` and `clear()`
* Test 6: Tests that your vector resizes correctly
* all: runs tests 1-6

## Grading

`Vector.h` is worth 100 points.
