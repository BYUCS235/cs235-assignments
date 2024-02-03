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

**For an explanation of how to use Grid.h, see <a href="#grid">here</a>**

```shell
$ ./maze test_files/solvable1.maze.txt solvable1.solution.txt
```

### Maze format

The first line of the maze file indicates the dimensions of the maze: number of
rows, number of columns, number of levels.

Each level in the maze starts with an empty line,
then an `n_rows` by `n_columns` block of text. `1` indicates a passable space, while `0` indicates a blocked space/wall. **A solution to the maze can only go through
passable spaces.**

The rows are numbered `0` to `n_rows` from top to bottom. The columns are
numbered `0` to `n_columns` from left to right. The levels are numbered `0` to
`n_levels` starting with the first level in the file to the last level in the
file.

The maze solution will always start at `(0, 0, 0)` and end at `(n_rows-1,
n_columns-1, n_levels-1)` (i.e. the opposite corner of the maze).

### Implementing the Lab
You should implement this lab using **recursion**. There is an old [video](https://youtu.be/IzNTe-8Vw14?si=-qzY0dmMGLi5mBss&t=213 "Lab 3 - Maze by Awesome CS 235 TA")
for this lab that explains the recursion through the maze very well. 

Some helpful timestamps:
- For an explanation of how to read the input files: 1:21 - 2:02
- For an explanation of how to recursively solve the maze: 3:33 - 8:33
- Bear in mind that the video is for an older version of this lab. You do
    not have to import the maze yourself, you do not have to generate a random maze, and you should use the provided Grid
    class instead of using a 3D array as the video suggests.

### Some tips for setting up your code
- Use the Grid class to make your maze (see <a href="#grid">Managing the 3D Maze Structure</a>).
- Create a recursive helper function such as `bool find_maze_path(Grid& grid, int row, int col, int level, vector<string>& solution) {}` to perform the recursion. This function should be called from `main()`.
- Store the path you find through the maze in some type of data structure (we recommend a vector or stack). Print the vector to the output file in your `main()` function.
- Your path structure can hold any data type you want in it. We recommend `std::string`, `vector<int>`, `vector<vector<int>>` (vector of vectors), or `tuple<int, int, int>` (make sure you `#include <tuple>` at the top of your code if you use this one)

### Some pseudocode for recursing through the maze
```bool find_maze_path(Grid& grid, int row, int col, int level, vector<string>& solution) {

    // check base cases (conditions under which your recursion should stop/return false)

    // check if you've visited this location before
    // If you run into an error such as `BAD_ACCESS`, you may not be checking or tracking your visitations correctly

    // check if you've hit a wall
    // depending on your logic, you may have to remove coordinates from your path here (since you've hit a dead end)

    // append your current location in the maze to your solution data structure when you've determined that you are at a valid location

    //Traverse the maze by recursing through`row + 1`, `row - 1`, `col + 1`, etc. one at a time
}
```
You do not have to follow this pseudocode exactly. There are many ways to do this lab. This logic should give you a good starting point.

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
Work through the example by hand so you know how to code your implementation.
1. The first line of the SOLUTION is "0 0 0" indicating that we start in the 0 row, the 0 column and the 0 level. "**1** 1 0 0"
2. The next line specifies "0 1 0" indicating that the solution moves 
## <a id="grid">Managing the 3D maze structure</a>

Use the provided `Grid` class to manage the 3D maze in memory. You can read [Grid.h](https://github.com/BYUCS235/cs235-assignments/blob/main/Unit03-Sorting/homework3b-maze/Grid.h "Grid.h") for more details on how to use it, but its basic usage looks like this:
```maze.cpp
#include "Grid.h" // make sure Grid.h is included in your maze.cpp file

Grid maze; // allocate a new, blank Grid
in >> maze; // read the entire input file into maze
std::cout << "The maze is " << maze.height() << " spaces tall, " << maze.width() << " spaces wide, and " << maze.depth() << " spaces deep" << std::endl; // access the maze's dimensions
std::cout << maze.at(row, column, level); // access the value at a specific location
maze.at(row, column, level) = 2; // set the value at a specific location. This is a great way to mark a location as visited.
```

Good job for reading all of the instructions!
## Debugging
Your assignments are getting complex enough now that you will need to adopt a different strategy for debugging.  Here are a few ideas that should be helpful:
1. You may have used "cout" to print out the values of variables in the past, but now the problems will be complex enough that you will probably be confused by a large number of debugging statements.  You ought to become familiar with the [Clion debugger](https://youtu.be/wUZyoAnPdCY?si=Su_ghWrnlPF0ZsW3).  It will allow you to set breakpoints at certain lines of your code and will let you display the values of all of your variables.
2. If you have been relying on the passoff autograder before, you ought to get used to creating your own test cases.  Although the "test_files directory has the cases that will be used by the autograder, you should create your own test cases with results that you know to allow you to debug your code more easily.  For example, you may want to create a 3 dimensional grid that is 2x2x2 so you can make sure that your basic functions are working.  Thoroughly test your code with your own test cases before trying to pass your code off with the autograder.
3. You will also want to test boundary conditions.  For example, create a test case that will cause your code to explore the left side, right side, top or bottom of the grid to make sure that your code can deal with these circumstances.

## Grading

`maze.cpp` is worth 100 points.

| Methods      | Points  |
|--------------|---------|
| solvable 1   | 15      |
| solvable 2   | 15      |
| solvable 3   | 20      |
| unsolvable 1 | 15      |
| unsolvable 2 | 15      |
| unsolvable 3 | 20      |
| **Total**    | **100** |
