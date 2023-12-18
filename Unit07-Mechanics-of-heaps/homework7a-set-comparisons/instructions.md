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
assignment's header. After that, you should be able to compile `main.cpp` with
the following command:

```console
> g++ -Wall -std=c++17 -o time main.cpp
```

and run it with the command below. The output is a table showing the time it
took to insert the specified number of elements into the set:

```console
> ./time
    N       Time to insert
---------- ----------------
     1000              0ms
    10000              9ms
   100000             56ms
  1000000            376ms
 10000000           4192ms
```

### A couple of notes:

* The C++ implementation of a set uses a balanced tree, similar to an AVL tree.
  Thus, like your BST and AVL implementations, the C++ implementation of a set
  is an ordered set. The C++ implementation of an unordered set uses a hash set,
  just like the set implementation that you created in HW 6a.

* If you did not complete HWs 2a, 5b, 5d, or 6a, you won't have your own code to
  do a comparison. Fear not -- just do comparisons among the implementations of
  sets that you do have.

## Running the test

Once you have gotten `main.cpp` to compile, run it for the 6 different
implementations of sets. To do this, you'll need to uncomment a line in
`main.cpp`. When you get `main.cpp`, you should see lines that look like this:

```cpp
// choose an implementation of a set by uncommenting the appropriate line
// below
std::set<int> set;
// std::unordered_set<int> set;
// VectorSet<int> set;
// BST<int> set;
// AVL<int> set;
// HashSet<int> set;
```

Since all these lines declare a variable named `set` and thus conflict, only one
can be uncommented at a time. To choose a set to test, uncomment the line
declaring `set` to be of the type that you want to test, then recompile and run
it again. **You must recompile for the change to take effect! If you don't, the
executable from the last compilation will run, testing the set that you already
tested.**

Fill in the following table as you run the tests. If any of the implementations
is taking an inordinate amount of time (e.g., several minutes) to complete, you
can just consider the smaller sizes of N that completed and mark the bigger
sizes that didn't finish as TSTT (too slow to test).

| N | `std::set` | `std::unordered_set` | `VectorSet` | `BST` | `AVL` | `HashSet` |
|------------|---|---|---|---|---|---|
| 1,000      |   |   |   |   |   |   |
| 10,000     |   |   |   |   |   |   |
| 100,000    |   |   |   |   |   |   |
| 1,000,000  |   |   |   |   |   |   |
| 10,000,000 |   |   |   |   |   |   |

Additionally, you should go through this process (testing all set
implementations and recording their runtimes in the table) twice: once for
sequential data (inserting 0..N in order) and once for random data (inserting N
random numbers). To do this, you'll need to modify `main.cpp` again. In
`main.cpp`, inside two nested `for` loops, there should be lines that look like
this:

```cpp
// choose whether to insert sequential or random data by
// uncommenting the appropriate line below

// SEQUENTIAL DATA
set.insert(i);

// RANDOM DATA
// set.insert(rand());
```

Choose whether to insert sequential or random data by uncommenting the
appropriate line. Remember to recompile after modifying `main.cpp`!

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
