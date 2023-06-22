# HW 4d

## Vector Iterator

Implement a simple dynamically-allocated array in `Vector.h` with support for *for-each* syntax.

In addition to the functionality described in [HW 4c Vector](../homework4c-vector/instructions.md), this submission should:

- Implement `begin()` and `end()` that return `Iterator` objects for the first and one past the last elements
- Implement the `Iterator` class with 
  - `operator*()` - retrieve the value of the current item
  - `operator++()` - advance to the next item
  - `operator==()` - return true if the two iterators are equal
  - `operator!=()` - return the opposite of `operator==()`

**Grading**

`Vector.h` is worth 100 points.
