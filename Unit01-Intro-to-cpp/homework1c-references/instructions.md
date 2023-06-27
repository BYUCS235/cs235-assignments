# HW 1c

## Sort Three Strings

Write a program in `sort.cpp` that sorts three command-line arguments (strings) in ascending order.

- You should implement a function `void sort(std::string& a, std::string& b, std::string& c)`
  - Modify `a`, `b`, and `c` directly to sort the strings
- The program should output the sorted strings separated by a space, followed by a newline
- If the program is not run with the correct number of arguments, print a usage message to `std::cerr` and exit with a return code of 1

You should build on the starter code in `sort.cpp`

### Example

```
$ ./sort baa baaa baaaaa
baa baaa baaaaa
$ ./sort aba zzz aaa
aaa aba zzz
```

## Head

Write a `head` program in `head.cpp`.

- The `head` program should read the first `n` lines of a file or standard input
  - If `n` isn't provided, print 10 lines
  - If no file is provided, read from standard input
- If the input file does not exist, the program should print an error message and exit
- If more lines are requested than the input file has, the program should just print the entire file
- Follow the formatting demonstrated in the example

### Example

**`myfile.txt`**
```
line 1
line 2
line 3
line 4
line 5
line 6
line 7
```

**Usage**
```
$ head -5 myfile.txt
line 1
line 2
line 3
line 4
line 5
$ cat myfile.txt | head -2
line 1
line 2
$ head -1000 file_that_does_not_exist.txt
ERROR: can't open file_that_does_not_exist.txt
```

## Grading

`sort.cpp` and `head.cpp` are both worth 50 points.
