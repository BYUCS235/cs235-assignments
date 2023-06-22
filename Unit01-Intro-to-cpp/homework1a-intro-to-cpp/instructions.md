# HW 1a

## Calculator

Write a calculator program in `calculator.cpp`.

- You can assume the user always provides valid inputs
  - e.g. the test will not enter `lizard` when the program expects a number
  - You won't be asked to divide or mod by zero
- Support `add`, `subtract`, `multiply`, `divide`, and `mod` (modulus) operations
  - Each of these operations takes a `left operand` and `right operand`
- The program should exit when given an empty operation
- Follow the formatting demonstrated in the example

**Example**

```
operation: add
left operand: 1
right operand: 2
3
operation: add
left operand: 5
right operand: -7
-2
operation: asdf
asdf isn't a valid operation
operation: 
```

## Numbers Divisible By

Write a program `numbers_divisible_by.cpp` that takes in three integer command line arguments: `start`, `end`, and `divisor`. 
The program should output all the integers between `start` and `end`, inclusive, that are divisible by `divisor`.

- You can assume the user always provides valid integer inputs
- If the `start` value is less than the `end` value, the program should iterate in increasing order
- If the `start` value is greater than or equal to the `end` value, the program should iterate in decreasing order
- Each integer divisible by the `divisor` should be output on a separate line

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

## Grading

`calculator.cpp` and `numbers_divisible_by.cpp` are each worth 50 points.

