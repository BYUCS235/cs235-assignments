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
$ uniq input.txt
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

`uniq.cpp` is worth 100 points.