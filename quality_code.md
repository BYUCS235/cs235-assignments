# Quality Code

When you write code, you want to write code that is easy to read, understand, debug, and maintain. In this section, we will cover the conventions for writing quality code in C++. These conventions include style and decomposition.

# Style

In this section, we will cover the style conventions for writing C++ code. These conventions are important because they help you write code that is easy to read and understand. When you write code that is easy to read and understand, it is easier to debug and maintain. Aspects of style that we will cover include: naming conventions, brackets, and whitespace.

## Case

There are many different ways to name things in programming. For example, you can use snake case or camel case. 

In this class, you are encouraged to use whichever case you prefer but make sure to be consistant from program to program. 

### Snake case

Is when you use lowercase letters and separate words with underscores. For example:

```c++
// Snake case 
std::string pie_flavor = 'key lime';

void get_flavors() {
    // code here
}
```

### Camel case

Is when you use lowercase letters for the first word and uppercase letters for the first letter of each subsequent word. For example:

```c++
// Camel case
std::string pieFlavor = 'key lime';

void getFlavors() {
    // code here
}
```

Again in this class, we encourage you to use which ever case you prefer but make sure to be consistant from program to program.
 
## Brackets

There are two conventions for brackets: K&R style and Allman style.

Feel free to use either style, but be consistent from program to program.

### K&R style

- Opening brackets go on the same line as the function declaration.

```c++
// K&R style
int main() {
    // code here
}
```

### Allman style

- Opening brackets go on the next line.

```c++
// Allman style
int main() 
{
    // code here
}
```

Again, feel free to use either style, but be consistent from program to program.
 
## Naming

### Variables

- Be consistent with your choice of case.
- Be descriptive with variable names.

```c++
// Good
std::string firstName = 'Emma'
std::string lastName = 'Smith'
int smallNumber = 5
std::string pokemonType = 'water'

// Bad
std::string first_name = 'Emma'
std::string last_Name = 'Smith'
int smallNumber = 5
std::string PokemonType = 'water'

// REALY BAD
std::string Thing = 'Emma'
std::string thing_One = 'Smith'
int ThatOne = 5
std::string other = 'water'
```

In the example above, the good example uses the same case for variable names and is descriptive. The bad example uses different cases for variable names. The really bad example uses non-descriptive variable names.

### Functions

- Be consistent with your choice of case.
- Be descriptive with function names.

```c++
// snake case
double calculate_area_of_circle(int radius) {
    return 3.14 * radius * radius;
}

// camel case
double calculateAreaOfCircle(int radius) {
    return 3.14 * radius * radius;
}
```

### Arguments

- Be consistent with your choice of case.
- Be descriptive with function arguments.

```c++
# Good
def calculate_area_of_circle(int radius) {
    return 3.14 * radius ** 2
}

# Bad
def calculate_area_of_circle(int foo) {
    return 3.14 * foo ** 2
}
```

In the example above, the good example uses descriptive function arguments. The bad example uses non-descriptive function arguments.

## White space

### Indentation

- Keep your indentation consistent.

```c++
// Good
int main() {
    int radius = 5;
    double area = calculate_area_of_circle(radius);
    std::cout << area << std::endl;
    return 0;
}

// Bad
int main() {
  int radius = 5;
    double area = calculate_area_of_circle(radius);
  std::cout << area << std::endl;
        return 0;
}
```

In the example above, the good example uses consistent indentation. The bad example does not use consistent indentation.

### Blank lines

- Use 1 blank line between functions.

```c++
// Good
void function1() {
    // code here
}

void function2() {
    // code here
}

// Bad
void function1() {
    // code here
}


void function2() {
    // code here
}

// REALLY BAD
void function1() {
    // code here
}


void function2() {
    // code here
}




void function3() {
    // code here
}
```

In the example above, the good example uses 1 blank line between functions. The bad example does not use blank lines between functions. The really bad example uses inconsistent blank lines between functions.

### Spaces before and after operators

- Use 1 white space before and after operators.

```c++
// Good
double area = 3.14 * radius * radius;

// Bad
double area = 3.14*radius*radius;
```

In the example above, the good example uses 1 space before and after operators. The bad example does not use spaces before and after operators.

# Decomposition

In this section, we will cover the decomposition conventions for writing c++ code. Decomposition is the process of breaking your code into smaller, more manageable pieces. When you decompose your code, you make it easier to read, understand, debug, and maintain. Aspects of decomposition that we will cover include: `#include` statements, functions, and more.

## `#include`

- Put your `#include` statements at the top of your file.

```c++
// Good
#include <iostream>

// Bad
int main() {
    #include <iostream>
    std::cout << 'Hello, World!' << std::endl;
    return 0;
}
```

In the example above, the good example puts the `#include` statement at the top of the file. The bad example puts the `#include` statement inside the `main` function.

## Statments

- Put one statement per line.

```c++
// Good
int main() {
    int radius = 5;
    double area = calculate_area_of_circle(radius);
    std::cout << area << std::endl;
    return 0;
}

// Bad
int main() {
    int radius = 5; double area = calculate_area_of_circle(radius); std::cout << area << std::endl; return 0;
}
```

In the example above, the good example puts one statement per line. The bad example puts multiple statements on one line.

## Functions

- Break your code into functions.
- Each function should do one thing.
- Each function should be small and focused.

```c++
// Good
double calculate_area_of_circle(int radius) {
    return 3.14 * radius * radius;
}

double calculate_area_of_square(int side) {
    return side * side;
}

// Bad
double calculate_area(int radius, int side) {
    double area = 3.14 * radius * radius;
    area += side * side;
    return area;
}
```

In the example above, the good example breaks the code into functions. Each function does one thing and is small and focused. The bad example does not break the code into functions.

# General Example

```c++
#include <cstdlib>
using std::atoi;

#include <iostream>
using std::cout;
using std::endl;

#include "where.h"

void swap(int &first, int &second)
// void swap(int first, int second)
{
    WHERE(first);
    WHERE(second);
    cout << "first: " << first << endl;
    cout << "second: " << second << endl;
    
    cout << "swap first and second" << endl;
    cout << "i.e. swap data at " << &first << " and " << &second << endl;
    // The & operator gets the location of the variable

    int tmp = first;
    first = second;
    second = tmp;
    
    cout << "first: " << first << endl;
    cout << "second: " << second << endl;
}

int main(int argc, char **argv)
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    WHERE(a);
    WHERE(b);

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    swap(a, b);

    WHERE(a);
    WHERE(b);
    
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
}
```

In the example above, the code is broken into functions. Each function does one thing and is small and focused. The code is easy to read, understand, debug, and maintain.

