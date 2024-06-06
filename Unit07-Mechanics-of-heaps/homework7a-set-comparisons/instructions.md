# HW 7a: Comparing Implementations of Sets

*If anything in this assignment seems confusing or stupid to you, feel free to
modify it so that it is a better learning experience for you. The grading will
not be stringent on whether you checked the boxes or not.*

*If you have not completed HWs 2b, 5b, 5d, or 6a, you can still do this lab by
running the tests on what you do have completed.*

In this assignment, you will compare the performance of various implementations
of sets. In HWs 2b, 5b, 5d, and 6a, you created four different implementations
of sets: a vector set, a binary search tree (BST), an AVL tree, and a hash set.
You will compare the runtime of inserting different amounts of elements into
your sets and the sets provided in the C++ standard library.

After you compute the runtimes of your various set implementations, 
you will meet with another student in class to compare results. 
Compare your runtimes and implementations. 

## Setting up

Copy your completed `VectorSet.h`, `BST.h`, `AVL.h`, and `HashSet.h` files into
this assignment's folder. `main.cpp`, which has the code that times the insert
operations, `#include`s all four files, so it will not be able to compile
without them. However, if you have not completed any of these assignments,
simply delete the `#include` directive in `main.cpp` that includes the
assignment's header and remove the associated lines in the `main` method. 

After that, you should be able to compile `main.cpp` with
the following command:

```console
$ g++ -Wall -std=c++17 -o perf main.cpp
```

The output is a table showing the time it
took to insert the specified number of elements into 
each set implementation for both *sequential* data and *random* data.


### A couple of notes:

* The C++ implementation of a set uses a balanced tree, similar to an AVL tree.
  Thus, like your BST and AVL implementations, the C++ implementation of a set
  is an ordered set. The C++ implementation of an unordered set uses a hash set,
  just like the set implementation that you created in HW 6a.

* If you did not complete HWs 2a, 5b, 5d, or 6a, you won't have your own code to
  do a comparison. Fear not -- just do comparisons among the implementations of
  sets that you do have.

* Empirical measurements of runtime are always noisy. Specific runtimes can be influenced
  by whether other things are running at the same time (did your email client check your
  email while the test was running?) as well as the current state of your operating system.
  It's not a bad idea to run the tests a few times in order to get a feel for how each 
  implementation actually performs.

## Running the test

Fill in the following table after you run the tests. 
Fill out the table for both the sequential and the random data.

| N   | `std::set` | `std::unordered_set` | `VectorSet` | `BST` | `AVL` | `HashSet` |
| --- | ---------- | -------------------- | ----------- | ----- | ----- | --------- |
|     |            |                      |             |       |       |           |
|     |            |                      |             |       |       |           |
|     |            |                      |             |       |       |           |
|     |            |                      |             |       |       |           |
|     |            |                      |             |       |       |           |

If any of the implementations
is taking an inordinate amount of time (e.g., several minutes) to complete, you
can put a limit on the size of `N` passed to that data structure. 
For example, to limit your `VectorSet` to `N < 12000`:

```c++
run_performance<VectorSet<int>>("VectorSet", true, 12000);
```

In the table above, simply put **TSTT** (too slow to test) in the appropriate cells.

## Comparing Results

Now that you've collected these data, meet with another student from the course to discuss the following questions:

1.  Based on the times you recorded, what is the Big-Oh of `insert` for each of
    these six implementations of sets?

2.  Are these Big-Ohs what you expected them to be? Why or why not? Be sure to
    explore any surprises that you see in the data. You should compare the
    Big-Ohs to the theoretical Big-Ohs that you have learned about (in class,
    through quizzes, etc.). Are the implementations you created as efficient as
    they should be? If not, can you explain why?

3.  How did the results change based on ordered data verses random data? Make
    sure you can explain the similarities and differences.

## Grading

After you have finished this assignment, complete the HW 7a quiz on Canvas to
get credit.
