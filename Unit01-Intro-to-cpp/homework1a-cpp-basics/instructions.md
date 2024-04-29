# HW 1a

## Numbers Divisible By

Write a program `numbers_divisible_by.cpp` that takes in three integer command line arguments: `start`, `end`, and `divisor`. 
The program should output all the integers between `start` and `end`, inclusive, that are divisible by `divisor`.

- The integers (start, end, etc.) will **NOT** be entered using `cin`. They will be given on the command line and stored in `argv`.
- You can assume the user always provides valid **integer** inputs (including negatives)
- If the `start` value is less than the `end` value, the program should iterate in increasing order
- If the `start` value is greater than or equal to the `end` value, the program should iterate in decreasing order
- Each integer divisible by the `divisor` should be output on a separate line

#### A Note on using argv[]
`argv` as seen in the `main` function stores arguments given on the command line. For example, for the command 

```bash
% ./numbers_divisible_by 1 10 2
``` 

it will store `argv[0]` representing `./numbers_divisible_by`, `argv[1]` representing `1`, `argv[2]` representing `10`, etc.

**Example**

```
$ ./numbers_divisible_by 1 10 2
2
4
6
8
10
```

```
$ ./numbers_divisible_by 10 1 3
9
6
3
```

### Collatz

The Collatz conjecture states that for any positive integer:

- if the number is even, divide it by 2
- if the numbers is odd, multiply it by 3

and that by following these steps, all sequences will eventually reach 1.

See also <https://en.wikipedia.org/wiki/Collatz_conjecture>

Write program that prints the Collatz sequence from the starting value (which is provided as a commandline argument). Stop when you reach 1. 

**Example**

```bash
% ./collatz 10
10
5
16
8
4
2
1
```

### Square Root

#### Background

There are many ways to implement the square-root function. You get to implement one of them.

When performing a binary search, you need a lower and upper bound to your search space. You check the middle value, and if it was too large, it becomes the upper bound of the search space; if it was too small, it becomes the lower bound of the search space. Then you check the middle value again, etc.

You can use binary search to estimate the square-root function:

- Start with 0 being the lower bound and your input value as the upper bound
- While the difference between the square of the value (i.e. `val * val`) and your input is greater than the desired precision, adjust your lower or upper bound and value and try again.

While there are many changes you might make to improve this algorithm, as well as other more efficient algorithms you might implement, the requirement of this exercise is to implement the provided algorithm.

#### Instructions

Write a program that estimates the square root of the input value using binary search.

- The input value is passed as a commandline argument
- The program prints each intermediate value in the binary search
  - Use the formatting shown below
  - Include the square of the value in parentheses
- The program stops when the difference between the square of the value and the input is less than `0.0001`
- The initial lower bound should be 0
- The initial upper bound should be the input value
- If the user inputs a negative number, print the error shown in the examples and exit with a non-zero exit code
- The program should support `double` inputs (not `int`)

**NOTE**: you can use `abs` from `<cstdlib>` to get the absolute value.

```c++
#include <cstdlib>
using std::abs;
```

**Examples**
```bash
% ./sqrt 2                             
1 (1)
1.5 (2.25)
1.25 (1.5625)
1.375 (1.89062)
1.4375 (2.06641)
1.40625 (1.97754)
1.42188 (2.02173)
1.41406 (1.99957)
1.41797 (2.01064)
1.41602 (2.0051)
1.41504 (2.00234)
1.41455 (2.00095)
1.41431 (2.00026)
1.41418 (1.99992)
```

```bash
% ./sqrt 3.1415926
1.5708 (2.4674)
2.35619 (5.55165)
1.9635 (3.85531)
1.76715 (3.1228)
1.86532 (3.47942)
1.81623 (3.2987)
1.79169 (3.21015)
1.77942 (3.16633)
1.77328 (3.14453)
1.77021 (3.13366)
1.77175 (3.13909)
1.77251 (3.14181)
1.77213 (3.14045)
1.77232 (3.14113)
1.77242 (3.14147)
1.77247 (3.14164)
```

```bash
% ./sqrt -7
Input must be greater than 0
```

## Grading

`numbers_divisible_by.cpp`, `collatz.cpp`, and `sqrt.cpp` will be graded as follows:

| Methods           | Points  |
|-------------------|---------| 
| going up          | 6       |
| going down        | 6       |
| up with bounds    | 6       |
| down with bounds  | 6       |
| negative and zero | 6       |
| **Num Div By**    | **30**  |
| starting at 5     | 7.5     |
| starting at 8     | 7.5     |
| starting at 17    | 7.5     |
| starting at 20    | 7.5     |
| **Collatz**       | **30**  |
| negative input    | 8       |
| int input         | 8       |
| double input      | 8       |
| sqrt 11           | 8       |
| sqrt 12.25        | 8       |
| **Sqrt**          | **40**  |
| **Total**         | **100** |
