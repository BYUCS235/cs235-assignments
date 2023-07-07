# HW 3b - 3D Maze Solver

## Purpose

This homework will help you practice recursion.

## Background

Two SCUBA diving buddies have encountered a large, box-shaped storage facility
inside the hull of the Heian Maru, a 512' submarine tender lying on the bottom
of Truk Lagoon at 108'. The storage facility is composed of large, cubic cells,
some of which can be entered and some which cannot. The only exterior walls that
are missing are on the front of the storage facility in the upper left corner,
and on the rear of the storage facility in the lower right corner. The divers
wish to determine a path through the storage facility.

## Requirements

Write a 3D maze solver program in `maze.cpp`. The first command-line argument is
the maze file and the second argument is the solution output file:

```shell
./maze test_files/solvable1.maze.txt solvable1.solution.txt
```

### Maze format

The first line of the maze file indicates the dimensions of the maze: number of
rows, number of columns, number of levels.

The layout of each level is presented. Each level starts with an empty line,
then an `n_rows` by `n_columns` block of text. `1` indicates a passable space,
while `0` indicates a blocked space. A solution to the maze can only go through
passable spaces.

The rows are numbered `0` to `n_rows` from top to bottom. The columns are
numbered `0` to `n_columns` from left to right. The levels are numbered `0` to
`n_levels` starting with the first level in the file to the last level in the
file.

The maze solution will always start at `(0, 0, 0)` and end at `(n_rows-1,
n_columns-1, n_levels-1)` (i.e. the opposite corner of the maze).

### Solution format

If the maze has no solution, print `NO SOLUTION` on the first line of the output
file and exit.

If the maze has a solution, print `SOLUTION` on the first line of the output
file. Then print the coordinates of the solution, one coordinate per line,
starting with `0 0 0` (separate each coordinate by a space).

### Example

#### Maze

```
3 4 3

1 1 0 0
0 1 0 0
0 1 1 0

0 0 0 0
0 0 0 0
0 0 1 0

0 0 0 0
0 0 0 0
0 0 1 1
```

#### Solution

```
SOLUTION
0 0 0
0 1 0
1 1 0
2 1 0
2 2 0
2 2 1
2 2 2
2 3 2
```

## Managing the 3D maze structure

Use the provided `Grid` class to manage the 3D maze in memory. You can read
[solution/Grid.h](solution/Grid.h) for more details on how to use it, but its
basic usage looks like this:
```cpp
#include "Grid.h"

Grid maze; // allocate a new, blank Grid
in >> maze; // read from an input stream into a Grid
std::cout << "The maze is " << maze.height() << " spaces tall, " << maze.width() << " spaces wide, and " << maze.depth() << " spaces deep" << std::endl; // access the maze's dimensions
std::cout << maze.at(row, column, level); // access the value at a specific location
maze.at(row, column, level) = 2; // set the value at a specific location
```

## Grading

`maze.cpp` is worth 100 points.