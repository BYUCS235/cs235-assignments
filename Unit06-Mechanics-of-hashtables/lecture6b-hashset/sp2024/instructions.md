# HW 6a

## HashSet

Implement a simple `HashSet` class in `HashSet.h`.

- You may implement hashset using chaining or open-addressing
- Implement the `insert`, `remove`, `contains`, `clear`, and `size` operations
- Grow the hash table when its load factor (defined as the number of items in the HashSet divided by the number of buckets) gets too big
- Use `std::hash` (found in the header `<functional>`) as your hash function
  - e.g. `size_t hashcode = std::hash<string>{}("foobarbaz");`

## Grading

`HashSet.h` is worth 100 points.

| Methods                | Points   |
|------------------------|----------|
| insert                 | 20       |
| contains               | 20       |
| remove                 | 20       |
| size & clear           | 10       |
| re-hashing stress test | 30       |
| **Total**              | **100**  |