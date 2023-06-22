from byu_pytest_utils import cache, compile_cpp, dialog_exec, max_score, test_files


# This compiles reformat.cpp for all the tests to use
@cache
def reformat_bin():
    return compile_cpp('reformat.cpp', output_exec='reformat')


# This generates a test that checks that reformat works (since reformat is such
# a simple program, there aren't really different functionalities to test)
@max_score(25)
@dialog_exec(
    test_files / 'reformat_test1.dialog.txt', reformat_bin,
    test_files / 'reformat_test1.input.txt', 'reformat_test1.output.txt',
    output_file='reformat_test1.output.txt'
)
def test_1():
    ...


# This also generates a test that checks that reformat works (again, since
# reformat is such a simple program, there aren't really different
# functionalities to test)
@max_score(25)
@dialog_exec(
    test_files / 'reformat_test2.dialog.txt', reformat_bin,
    test_files / 'reformat_test2.input.txt', 'reformat_test2.output.txt',
    output_file='reformat_test2.output.txt'
)
def test_2():
    ...
