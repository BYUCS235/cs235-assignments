# CS 235 - Assignment Files and Instructions

The instructions and required files for each CS 235 assignment are found in this repo.

## Homework Files

In each homework folder are the instructions for that assignment and the files you will need.

You should use the `.cpp` and `.h` files that are provided. Do not change the names of any files.

### Testing your code

The `test_*.py` files run the tests for your submission. To run these locally:

1. Make sure you have `byu_pytest_utils` installed:

```
pip install byu_pytest_utils
```

2. In the homework folder, run:

```
python -m pytest -vv .
```

Once `byu_pytest_utils` is installed, your IDE may detect the tests, and you can run them and see the test output there.

The `test_files` folder contains files used for testing your submission.

The tests in Gradescope are identical to the tests provided in this repo.

### Understanding the tests

Some homework assignments just have `test_*.py` files. These files will show example invocations of your program with different commandline arguments (if required). They compare the output of your program to the specified `dialog.txt` file in `test_files`. 

A `dialog.txt` file shows what your program should print (or write to an output file).

Strings delimited by `<< >>` are inputs provided via STDIN to your program.

Some parts of the output are worth more than other parts (called "target regions"). These are identified by backticks (`\`\``). 

The first part of the target region is the expected text; the second part is the name of the region (used in the test output); and the third part is the percentage of points assigned to that region.

Some homework assignments will also have a `tests.cpp` file. This file is compiled with the files from your assignment.
Look through this file to understand what kinds of operations will be performed on your data structures. 

## Submitting Your Homework

Your assignments are submitted through Canvas (which in turn uses Gradescope). 

You should turn in only the `.cpp` and `.h` files that you modify or create.
 
## Cloning This Repository

We will be using Git to manage the homework files and instructions. To help you get started, here is a brief guide on how to use the essential Git commands for cloning, committing, and pulling the course repository.

### Step 1: Clone the repository

To get started, you'll first need to clone the class git repository. This will create a local copy of the repository on your computer.

- Open your terminal or Command Prompt.
- Navigate to the folder you would like to store the local copy of the class repository.
- Run the following command (replace <repository_url> with the actual URL of the course repository):

```
   git clone <repository_url>
```

This will create a new folder with the repository name containing all the starter files and instructions.

### Step 2: Commit your changes
As you work on your assignments, you can save a backup of your work by committing your changes.

- Navigate to your repository folder in the terminal or Command Prompt.
- Check the status of your changes using `git status`. This will show you any new, changed, or deleted files.
- Add the changed files to the staging area using `git add <file_name>` or `git add .` (to add all changes).
- Commit your changes using `git commit -m "Your commit message"` (Replace "Your commit message" with a brief description of the changes you made).

Your changes are now saved in your local repository.

You can also see and commit your changes in your IDE. 

### Step 3: Pull updates

To receive any updates to the instructions or starter files from the course repository, you'll need to pull the latest changes.

- Before pulling, make sure you have committed your current work following Step 2. This will help to avoid conflicts during the pull process.
- Run git pull to fetch and merge the latest changes from the remote repository.

If there are any conflicts between your local changes and the updates, Git will notify you. To resolve the conflicts, we recommend you use the *resolve conflicts* feature in your IDE.

After resolving conflicts, your repository will be up to date with the latest course materials.



