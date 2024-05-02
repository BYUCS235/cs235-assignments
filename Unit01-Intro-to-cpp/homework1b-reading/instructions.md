# Homework 1b

If you need inspiration, look at the examples from the lecture in [../lecture2a-reading](../lecture2a-reading/)

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

Read `cin` using `getline`, not `>>`. 

Because the `>>` operator ignores whitespace, using it makes it impossible to enter an empty string as an input for the operation.

Look at [`guessing_game.cpp`](../lecture02-reading/guessing_game.cpp) for an example of how to use `getline` for this use-case.

**Example**

```
$ ./calculator
operation: add
left operand: 1
right operand: 2
3
operation: asdf
asdf isn't a valid operation
operation: add
left operand: 5
right operand: -7
-2
operation: 
```

## Reformat

Write a program that reads in a file containing a list of names, point scores, and a factor. The program should reformat and output the data to a new file, where the points are multiplied by the given factor for each name.

Save your program as `reformat.cpp`.

- Accept the input file name and the output file name as command line arguments
- You can assume the input file is formatted correctly
- The input file format:
  - Each line contains a first name, last name, points (integer), and factor (double) separated by spaces
  - There is no trailing whitespace
- The output file format:
  - Each line contains the last name, a comma, the first name, a colon, and the recalculated points (as a double)
  - There is no trailing whitespace

### Example

`input_file.txt`
```
Alice Smith 10 1.5
Bob Johnson 5 2.0
```

**Usage**
```
$ ./reformat input_file.txt output_file.txt
```

`output_file.txt`
```
Smith, Alice: 15
Johnson, Bob: 10
```

## Longest Line

Write a program in `longest_line.cpp` that reads an input file, and outputs the line containing the largest number of **words** (not characters) to the console (i.e. `cout`, not a file).

- You will receive a file name as a command line argument
  - `argc` will always be 2
- You can assume spaces are always used to separate words
- By *word* we mean any contiguous chunk of non-whitespace characters
  - e.g. `1234`, `no`, and `abcdef!` all count as words
- If there are multiple lines with the same number of words, output the **first** one encountered

### Example

`example.txt`:
```
abcd efgh ijkl
abcd 1234 efg
cdef qwerty 123 qwe
woot foo bar baz
```

**Usage** 
```
$ ./longest_line example.txt
```

**Output**
```
cdef qwerty 123 qwe
```

## Grading

`calculator.cpp`, `reformat.cpp`, and `longest_line.cpp` will be graded as follows:

| Methods           | Points  |
|-------------------|---------|
| invalid operation | 5       |
| add               | 5       |
| subtract          | 5       |
| multiply          | 5       |
| divide            | 5       |
| mod               | 5       |
| **Calculator**    | **30**  |
| test 1            | 17.5    |
| test 2            | 17.5    |
| **Reformat**      | **35**  |
| test 1            | 17.5    |
| test 2            | 17.5    |
| **Longest line**  | **35**  |
| **Total**         | **100** |