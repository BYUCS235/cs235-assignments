from byu_pytest_utils import cache, compile_cpp, dialog_exec, max_score, test_files


# This compiles longest_line.cpp for all the tests to use
@cache
def longest_line_bin():
    return compile_cpp('longest_line.cpp', output_exec='longest_line')


# This generates a test that checks that longest_line works (since longest_line
# is such a simple program, there aren't really different functionalities to
# test)
@max_score(25)
@dialog_exec(
    test_files / 'longest_line_test1.dialog.txt',
    longest_line_bin, test_files / 'longest_line_test1.input.txt'
)
def test_1():
    ...


# This also generates a test that checks that longest_line works (again, since
# longest_line is such a simple program, there aren't really different
# functionalities to test)
@max_score(25)
@dialog_exec(
    test_files / 'longest_line_test2.dialog.txt',
    longest_line_bin, test_files / 'longest_line_test2.input.txt'
)
def test_2():
    ...
