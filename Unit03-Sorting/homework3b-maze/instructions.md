# HW 3b - 3D Maze Solver
**READ THROUGH ALL OF THE INSTRUCTIONS BEFORE BEGINNING THIS LAB. THERE ARE SOME HELPFUL TIPS AT THE BOTTOM**

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

**Read to the bottom to understand Grid.h**

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

### Implementing the Lab
You should implement this lab using **recursion**. There is an old <a href=https://youtu.be/IzNTe-8Vw14?si=-qzY0dmMGLi5mBss&t=213>video</a> 
for this lab that explains the recursion through the maze very well. 
Some helpful timestamps:
    -For an explanation of how to read the input files: 1:21 - 2:02
    -For an explanation of how to recursively solve the maze: 3:33 - 8:33
    -Bear in mind that the video is for an older version of this lab. You do
    not have to import the maze yourself, and you should use the provided Grid
    class instead of using a 3D array as the video suggests.

## Some tips on how to set up your code:
    -Use the Grid class to make your maze (see "Managing the 3D Maze Structure").
    -Create a recursive helper function such as `bool find_maze_path(Grid& grid, int row, int col, int level, vector<string>& solution) {}`
    to perform the recursion. This function should be called from `main()`.
    -Store the path you find through the maze in some type of data structure
    (we recommend a vector or stack). Output the vector to the output 
    file in your `main()` function.
    -Your path structure can hold any data type you want in it. We recommend
    `std::string`, `vector<int>` (vector of vectors), or `tuple<int, int, int>` 
    (make sure you `#include <tuple>` at the top of your code if you use this one)

## Tips for the recursion:
    -Start by determining your base cases (the conditions under which your
    recursion should stop/return false).
    -Check if you have visited your current location before.
    This will require you to find a way to track visited locations by either
    storing them or altering the maze. If you run into an error such as `BAD_ACCESS`,
    you may not be checking or tracking your visitations correctly.
    -Check if you've hit a wall (the current location is a 0).
    -Navigate the maze by recursing through `row + 1`, `row - 1`, `col + 1`, etc.
    one at a time.
    -Depending on the logic of your recursion, you may have to remove coordinates
    from your path when a potential hits a wall.
    -Append to your solution structure only when you have determined that you are
    at a valid location (the current location contains a 1).

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

Use the provided `Grid` class to manage the 3D maze in memory. You can read <a href="https://github.com/BYUCS235/cs235-assignments/blob/main/Unit03-Sorting/homework3b-maze/Grid.h>
Grid.h</a> for more details on how to use it, but its
basic usage looks like this:
```maze.cpp
#include "Grid.h"

Grid maze; // allocate a new, blank Grid
in >> maze; // read the entire input file into maze
std::cout << "The maze is " << maze.height() << " spaces tall, " << maze.width() << " spaces wide, and " << maze.depth() << " spaces deep" << std::endl; // access the maze's dimensions
std::cout << maze.at(row, column, level); // access the value at a specific location
maze.at(row, column, level) = 2; // set the value at a specific location. This is a great way to mark a location as visited.
```

## Grading

`maze.cpp` is worth 100 points.
Good job for reading all of the instructions!

