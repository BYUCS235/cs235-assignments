# HW 2b

## VectorSet

Create a class template called `VectorSet` in the header file named `VectorSet.h`.

- **`VectorSet` should store elements in a `std::vector<T>`**
- Your class should provide the following public member functions:
  - `bool contains(T item) const`
    - Returns true if the `item` is in the set, and false otherwise
  - `bool insert(T item)`
    - Inserts `item` into the set if not already present
    - Returns true if the insertion was successful
    - Returns false if the `item` is already in the set
  - `bool remove(T item)`
    - Removes `item` from the set if present
    - Returns true if the `item` has been removed
    - Returns false if the `item` is not found in the set
  - `int size() const`
    - Returns the number of elements in the set
  - `bool empty() const`
    - Returns true if the set is empty
    - Returns false if the set has any elements
  - `void clear()`
    - Removes all elements from the set

### Example

```cpp
VectorSet<int> s1;
s1.insert(1); // Returns true
s1.insert(2); // Returns true
s1.insert(3); // Returns true
s1.insert(3); // Returns false
s1.size() // Returns 3
s1.contains(1) // Returns true
s1.remove(1) // Returns true
s1.size() // Returns 2
s1.empty() // Returns false
s1.clear();
s1.size() // Returns 0
```

## Grading

`VectorSet.h` is worth 100 points.