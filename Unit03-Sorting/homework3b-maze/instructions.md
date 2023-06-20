# HW 2b

## 3D Maze Solver

Write a 3D maze solver program in `maze.cpp`.

- Use the provided `Grid` class to manage the 3D maze
- The program should read the maze from a given input file and write the solution to the specified output file
- A solution path is a sequence of (row, column, level) coordinates and must start at (0, 0, 0)
- A path moves to an adjacent cell in the grid with a value of 1 and can change one coordinate at a time
- If there is no solution, the program should write "NO SOLUTION" to the output file

See [solution/Grid.h](solution/Grid.h) for the `Grid interface`. Its basic usage looks like this:
  ```c++
  Grid maze;  // allocate a Grid
  in >> maze; // read the Grid info from an input stream
  std::cout << "The maze is " << maze.height() << " spaces tall, " << maze.width() << " spaces wide, and " << maze.depth() << " spaces deep" << std::endl;
  std::cout << maze.at(row, column, level); // access the value at a specific location
  maze.at(row, column, level) = 2;          // set the value at a specific location
  ```

### Example

**`solvable1.maze.txt`**
```
3 4 5

1 1 1 1
0 0 0 1
0 0 0 1

0 0 0 0
0 0 0 0
0 0 0 1

0 0 0 0
0 0 0 0
0 0 0 1

0 0 0 0
0 0 0 0
0 0 0 1

0 0 0 0
0 0 0 0
0 0 0 1
```

**Expected Output File**
```
SOLUTION
0 0 0
0 1 0
0 2 0
0 3 0
1 3 0
2 3 0
2 3 1
2 3 2
2 3 3
2 3 4
```

## Grading

`maze.cpp` is worth 100 points.