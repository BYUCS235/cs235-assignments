# HW 1a

## Calculator

Write a calculator program in `calculator.cpp`.

- You can assume the user always provides valid inputs
  - e.g. the test will not enter `lizard` when the program expects a number
  - You won't be asked to divide or mod by zero
- Support `add`, `subtract`, `multiply`, `divide`, and `mod` (modulus) operations
  - Each of these operations takes a `left operand` and `right operand`
  - If the user enters an invalid operation (one that is not `add`, `subtract`, etc.), your program should print `{operation} isn't a valid operation` and prompt the user to enter another operation (see example).
- The program should exit when given an empty operation
- Follow the formatting demonstrated in the example

### A Word to the Wise
**DO NOT USE `cin` for this activity**. Because `cin` ignores all whitespace (including newlines), there is no way to pass an empty string as the operation with `cin` (it will continue to wait for input instead of exiting). Instead, use the provided `input()` function at the top of `main()`.

##### How to use `input()`

The provided `input()` function works much like the input function in Python. It takes the prompt you want to display to the user (e.g. `operation`, `left operand`, etc.), prints it, and returns the next **line** of user input (i.e. everything up to the next newline character).

NOTE: since `input()` returns a string type, you will have to convert the result into an integer for the left/right operands.

#### Example of how to use `input()`
```
  string operation = input("operation: ");
```

**Example**

```
$ ./calculator
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

- The integers (start, end, etc.) will **NOT** be entered using `cin`. They will be given on the command line and stored in `argv`.
- You can assume the user always provides valid integer inputs
- If the `start` value is less than the `end` value, the program should iterate in increasing order
- If the `start` value is greater than or equal to the `end` value, the program should iterate in decreasing order
- Each integer divisible by the `divisor` should be output on a separate line

#### A Note on using argv[]
`argv` as seen in the `main` function stores arguments given on the command line. For example, it will store the command `./numbers_divisible_by 1 10 2` with `argv[0]` representing `./numbers_divisible_by`, `argv[1]` representing `1`, `argv[2]` representing `10`, etc.

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

