# HW 4c

## Vector Class

Create a `Vector` class in `Vector.h`.

- Implement a dynamic array-based vector class that can hold elements of any data type
- Include the following public member functions:
  - `void push_back(T item)`: Append an item to the end of the vector
  - `void insert(T item, int position)`: Insert an item at a given position in the vector, shifting elements to the right
  - `void remove(int position)`: Remove the item at the given position, shifting elements to the left
  - `T& operator[](int index)`: Access the item at the given index, without bounds checking
  - `int size() const`: Return the number of elements in the vector
  - `void clear()`: Clear the vector, making it empty
- The class should automatically resize when necessary
- `insert`, `remove`, and `operator[]` should throw an `std::out_of_range` if the index is out of range

**Note**

All tests will require `operator[]` and `size` to be implemented so that the vector can be printed. 

## Grading

`Vector.h` is worth 100 points.
