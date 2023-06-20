# HW 6a

## HashSet

Implement a simple `HashSet` class in `HashSet.h`.

- You may implement hashset using chaining or open-addressing
- Implement the `insert`, `remove`, `contains`, `clear`, and `size` operations
- Grow the size of the hash table to reduce the load factor (defined as the number of items in the HashSet divided by the number of buckets) whenever the load factor exceeds `MAX_LOAD_FACTOR`
  - Upon growing, the new table should have a size equal to the current table's size times `GROWTH_FACTOR`
- Use `std::hash` (found in the header `<functional>`) as your hash function
  - e.g. `size_t hashcode = std::hash<string>{}("foobarbaz");`

## Grading

`HashSet.h` is worth 100 points.