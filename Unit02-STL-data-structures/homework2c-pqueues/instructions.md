# HW 2c

## Priority Queues

Write a priority queue program in `pqueues.cpp`.

- You can assume the user always provides valid inputs
  - e.g. the test will not enter non-numeric input when the program expects a number
  - you should use the provided input.h function for your inputs
- Support `add` and `take` operations:
  - `add` requires a `Name` and `Priority` input
  - `take` will display the next person in line according to their priority
    - Higher numbers indicate higher priority
    - If nobody is in the queue, print `There are no more people in line`
- Use a `std::priority_queue` to store the entries
- The entries should include the assigned priority and name, separated by " - "
- Pad priority numbers with a leading zero if they are in the range 0-9
- An empty operation exits the program
- Follow the formatting demonstrated in the example

### Example

```
What do you want to do? add
Name: Alice Krandall
Priority: 3
What do you want to do? add
Name: Bob Stevens
Priority: 10
What do you want to do? add
Name: Carol Bakedbean
Priority: 1
What do you want to do? take
10 - Bob Stevens
What do you want to do? take
03 - Alice Krandall
What do you want to do? take
01 - Carol Bakedbean
What do you want to do? take
There are no more people in line
What do you want to do? asdf
asdf isn't a valid operation
What do you want to do? 
```

## Grading

`pqueues.cpp` is worth 100 points.
