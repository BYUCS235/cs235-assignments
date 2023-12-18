# HW 1c

## Sort Three Strings

Write a program in `sort.cpp` that sorts three command-line arguments (strings) in ascending order.

- You should implement a function `void sort(std::string& a, std::string& b, std::string& c)`
  - Modify `a`, `b`, and `c` directly to sort the strings
- Sort the strings shortest length to longest length. If two strings are the same length, sort them alphabetically.
  <li>HINT: you can <a href="https://www.geeksforgeeks.org/comparing-string-objects-using-relational-operators-c/">compare</a> C++ strings using relational operators.</li>
  <li>HINT: sorting three items at a time is known as a "bubble sort".</li>
- The program should output the sorted strings separated by a space and followed by a newline
- If the program is not run with the correct number of arguments, print a usage message to `std::cerr` and exit with a return code of 1

Your code should be written in the `sort()` function found in `sort.cpp`.

### Example

```
$ ./sort baa baaa baaaaa
baa baaa baaaaa
$ ./sort aba zzz aaa
aaa aba zzz
```

## Head

Write a `head` program in `head.cpp`.

- The `head` program should read the first `n` lines of either a file or standard input
  - If `n` isn't provided, print 10 lines
  - If no file is provided, read the lines from standard input (`cin`)
- There are four possible scenarios for command-line arguments:
  1) No arguments: the program should read 10 lines from standard input.
  2) 1 argument that is an input file: the program should attempt to read 10 lines from the file.
  3) 1 argument that is a number of lines `n`: the program should read that number of lines from standard input.  
  -NOTE: Empty lines (`""`) count as valid input. The program should accept them the same way it accepts non-empty lines.
  4) 2 arguments: the program should read `n` lines from the file.
- If the input file does not exist, the program should print an error message and exit
- If more lines are requested than the input file has, the program should just print as many lines as the file has and no extras.
- Follow the formatting demonstrated in the example

### Examples
Click a hyperlink to navigate to a specific example:

<a href="#2args">Two arguments</a> | <a href="#1numlines">One argument: num lines</a> | <a href="#1inputfile">One argument: input file</a> | 
<a href="#notenoughlines">File with too few lines</a> | <a href="#filedne">File that does not exist</a>

#### <a id="2args">Two arguments-- number of lines && input file example</a>

**`sample_input_file.txt`**
```
line 1
line 2
line 3
line 4
line 5
line 6
line 7
```

**Expected output**
```
$ head -5 sample_input_file.txt
line 1
line 2
line 3
line 4
line 5
```

#### <a id="1numlines">One argument-- number of lines example:</a>
`cin` input provided by autograder/user is italicized. Expected program output is unitalicized.
**Expected output**
```
$ head -3
*input line 1*
input line 1
*input line 2*
input line 2
*input line 3*
input line 3
```
#### <a id="1inputfile">One argument-- filename example:</a>
**Expected output**

**`sample_input_file.txt`**
```
line 1
line 2
line 3
line 4
line 5
line 6
line 7
line 8
line 9
line 10
line 11
line 12
```

**Expected output**
```
$ head sample_input_file.txt
line 1
line 2
line 3
line 4
line 5
line 6
line 7
line 8
line 9
line 10
```
#### <a id="notenoughlines">File that does not have enough lines example:</a>
**`sample_input_file.txt`**
```
line 1
line 2
line 3
line 4
line 5
```

**Expected output**
```
$ head -9 sample_input_file.txt
line 1
line 2
line 3
line 4
line 5
```

#### <a id="filedne">File that does not exist example:</a>
**Expected output**
```
$ head -1000 file_that_does_not_exist.txt
ERROR: can't open file_that_does_not_exist.txt
```


## Grading

`sort.cpp` and `head.cpp` are both worth 50 points.
