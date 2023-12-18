# HW 3d

## Quicksort

Write a quicksort algorithm in `QS.h`.

- Your sorting algorithm should work for any data type `T` where the comparison operators (`<`, `>`, etc.) are defined (string, int, double, etc.).
- Your implementation should use the median-of-three method to select the pivot for sorting.
- Implement the following functions as part of your quicksort implementation:
  - `int medianOfThree(std::vector<T>& array, int left, int right)`
  - `int partition(std::vector<T>& array, int left, int right)`
  - `void sort(std::vector<T>& array)`

### Page Navigation
[MedianOfThree()](#implementing-medianofthree) | [partition()](#implementing-partition) | [sort()](#implementing-sort) | [example](#example-using-a-maincpp-of-your-own-creation) | [Testing using tests.cpp](#example-using-the-provided-testscpp-file) | [A guide to the test files](#a-guide-to-what-functions-each-of-the-tests-test)

### Implementing `medianOfThree`

`medianOfThree`'s purpose is to make it less likely for the algorithm to choose
a bad pivot. To do this, it:

1. Calculates the index in between `left` and `right`:
   $middle = \frac{left + right}{2}$
2. Sorts the values at `left`, `middle`, and `right` (HINT: this is the same type of sort as the one you did in HW 1c)

It then returns `middle`, which will be the index of the pivot that `partition`
will use.

### Implementing `partition`

`partition`'s purpose is to put all elements greater than the chosen pivot to
its right and all elements less than or equal to the pivot to its left. To do
this it follows the following pseudocode (it's important to follow this exactly
to match the autograder):

1. Call `medianOfThree` to find `middle`
2. Get the pivot value out of the way by swapping `array[left]` and `array[middle]` (we do this so the pivot value doesn't get overwritten)
   *Note: the pivot value is now located `array[left]` due to this swap*
3. Set `up` to `left + 1` and `down` to `right`
4. [Do](ttps://www.w3schools.com/cpp/cpp_do_while_loop.asp):
   1. Increment `up` while `up` refers to array elements less than or equal to the
      pivot value **AND** `up` has not reached `right`
   2. Decrement `down` while `down` refers to array elements greater than the pivot value **AND** `down` has not reached `left`
   3. If `up` is still less than `down`, swap `array[up]` and `array[down]`
   
   while `up` is to the left of `down`
5. Put the pivot back in the middle by swapping `array[left]` and `array[down]`
6. Return the pivot index (which is now `down`)

### Implementing `sort`

`sort` puts together the pieces you just wrote into a sorting
algorithm.

**To do this:**
1. Use a recursive helper function of your own creation (HINT: aside from taking in the array as a parameter, you will also want to track the leftmost and rightmost indices during the recursion). 
2. This helper function repeatedly calls `partition` until
the list is sorted.
3. You'll need to add in a base case to the function that detects when no more partitions need to be done (HINT: think of the values the leftmost index and rightmost index will be at when the array is sorted).

**Why this works:** 
* Once you call `partition` on either
the full array or a smaller portion of the array, the pivot value is in the
correct place in the array. This means we do not need to include the pivot when we call our sort function recursively.
* All elements greater than the pivot
are to its right, and all elements less than or equal to it are to its left.
* If the recursive helper function calls `partition` on its slice of the
array, it can then call itself on the slice of the array to the *left* of the
pivot as well as on the slice of the array to the *right* of the pivot (**excluding the pivot in both cases**).
* As smaller and smaller subsections of the original array are
partitioned, the list ends up sorted. 

### Example using a main.cpp of your own creation

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

### Example using the provided tests.cpp file

The following example will run the first automatic test:
```
g++ tests.cpp -o tests
./tests 1
```
**The possible tests for this assignment are 1, 2, 3, 4, 5, 6, 7, or all.**

### A Guide to what functions each of the tests test:
* Test 1: `MedianOfThree()`
* Test 2: `partition()`
* Test 3: `partition()` edge cases
* Test 4: more `partition()` edge cases
* Test 5: `sort()` (which calls `partition()`, which calls `MedianOfThree()`)
* Test 6: `sort()`
* Test 7: `sort()` with edge cases
* all: runs tests 1-7

## Grading

`QS.h` is worth 100 points.

You will be graded on the correct implementation of `medianOfThree`, `partition`, and `sort`.