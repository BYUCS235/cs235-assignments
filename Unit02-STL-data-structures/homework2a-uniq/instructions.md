# HW 2a 

## Unique Lines

Write a program in `uniq.cpp` that reads lines from a text input and outputs unique lines only.

- Read lines from a file if a filename is provided as a command-line argument, otherwise read lines from `stdin`
- Output unique lines in the order they appear in the input
- Do not output a line more than once

### Example

**`input.txt`**
```
orange
apple
banana
apple
orange
```

**Usage**
```
$ ./uniq input.txt
orange
apple
banana
``` 

Using `stdin` (`stdin` lines appear in italics):

```
$ ./uniq
*apple*
apple
*orange*
orange
*apple*
*banana*
banana
*orange*
```

## Grading
You should test your code on the examples in the test_files folder.  These test cases are similar to what the autograder will use.  You should be able to run your code on the input file and redirect output using ">" and then compare your output to the stdout file. For example:
```
./uniq file_test1.input.txt > file_test1.output.txt
diff file_test1.stdout.txt file_test1.output.txt
```
You can install ["Git Bash"](https://github.com/git-guides/install-git) if diff is not available on your computer.
When there are differences between the two files, you will see which line the difference occurs on and what the change should be.  For example, the following diff output:
```
% diff foo1.txt foo2.txt
4c4
< this
---
> 
```
indicates that a difference exists on line 4 and that the file foo2.txt should be changed on line 4 to have the text "this".

`uniq.cpp` is worth 100 points.
