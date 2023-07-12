# HW 3d

## Quicksort

Write a quicksort algorithm in `QS.h`.

- Your sorting algorithm should work for any data type `T` where the comparison operators (`<`, `>`, etc.) are defined.
- Your implementation should use the median-of-three method as a pivot selection strategy.
- Implement the following functions as part of your quicksort implementation:
  - `int medianOfThree(std::vector<T>& array, int left, int right)`
  - `int partition(std::vector<T>& array, int left, int right)`
  - `void sort(std::vector<T>& array)`

### Implementing `medianOfThree`

`medianOfThree`'s purpose is to make it less likely for the algorithm to choose
a bad pivot. To do this, it:

1. Calculates the index in between `left` and `right`:
   $middle = \frac{left + right}{2}$
2. Sorts the values at `left`, `middle`, and `right`

It then returns `middle`, which will be the index of the pivot that `partition`
will use

### Implementing `partition`

`partition`'s purpose is to put all elements greater than the chosen pivot to
its right and all elements less than or equal to the pivot to its left. To do
this it follows the following pseudocode (it's important to follow this exactly
to match the autograder):

1. Call `medianOfThree` to find `middle`
2. Get the pivot out of the way by swapping `array[left]` and `array[middle]`
3. Set `up` to `left + 1` and `down` to `right`
4. Do the following while `up` is to the left of `down`:
   1. Increment `up` until `up` points to the first element greater than the
      pivot value **OR** until `up` has reached `right`
   2. Decrement `down` until `down` points to the first element less than or
      equal to the pivot value **OR** until `down` has reached `left`
   3. If `up` is still less than `down`, swap `array[up]` and `array[down]`
5. Put the pivot back in the middle by swapping `array[left]` and `array[down]`
6. Return the pivot index (which is now `down`)

### Implementing `sort`

`sort`'s purpose is to put together the pieces you just wrote into a sorting
algorithm. To do this, it calls a recursive helper function (you'll have to
create that). The recursive helper function repeatedly calls `partition` until
the list is sorted. Here's why this works: once you call `partition` on either
the full array or a smaller portion of the array, the pivot value is in the
correct place in the array. Additionally, all elements greater than the pivot
are to its right, and all elements less than or equal to it are to its left.
Thus, if the recursive helper function calls `partition` on its slice of the
array, it can then call itself on the slice of the array to the left of the
pivot as well as on the slice of the array to the right of the pivot.
Eventually, as smaller and smaller subsections of the original array are
partitioned, the list ends up sorted. You'll need to add in a base case to the
recursive helper function that detects when no more partitions need to be done.

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