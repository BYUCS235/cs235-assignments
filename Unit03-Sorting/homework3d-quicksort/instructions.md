# HW 3d

## Quick Sort

Write a quicksort algorithm in `QS.h`.

- Your sorting algorithm should work for any data type `T` where the comparison operators (`<`, `>`, etc.) are defined.
- Your implementation should use the median-of-three method as a pivot selection strategy.
- Implement the following functions as part of your quicksort implementation:
  - `int medianOfThree(std::vector<T>& array, int left, int right)`
  - `int partition(std::vector<T>& array, int left, int right)`
  - `void sort(std::vector<T>& array)`

### Example

To use your quicksort implementation, include `QS.h` and use the `sort` function:

```cpp
#include "QS.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<int> array = {3, 7, -5, 10, 1};

    sort(array);

    for (const auto& item : array) {
        std::cout << item << " ";
    }

    return 0;
}
```

**Output**
```
-5 1 3 7 10
```

## Grading

`QS.h` is worth 100 points.

You will be graded on the correct implementation of `medianOfThree`, `partition`, and `sort`.