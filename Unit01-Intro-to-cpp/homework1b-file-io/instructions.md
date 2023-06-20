# HW 1b

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
./reformat input_file.txt output_file.txt
```

`output_file.txt`
```
Smith, Alice: 15
Johnson, Bob: 10
```

## Longest Line

Write a program in `longest_line.cpp` that reads an input file, and outputs the line containing the largest number of words.

- You will receive a file name as a command line argument
  - `argc` will always be 2
- You can assume spaces are always used to separate words
- You can assume words have no punctuation
  - e.g. `1234`, `no`, and `abcdef` all count as words
- You can assume the input file only has non-empty lines
- If there are multiple lines with the same number of words, output the first one encountered

### Example

`example.txt`:
```
abcd efgh ijkl
abcd 1234 efg
cdef qwerty 123 qwe
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

`reformat.cpp` and `longest_line.cpp` are both worth 50 points.
