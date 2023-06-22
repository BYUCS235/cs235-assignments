from byu_pytest_utils import cache, compile_cpp, dialog_exec, max_score, test_files


# This compiles uniq.cpp for all the tests to use
@cache
def uniq_bin():
    return compile_cpp('*.cpp', output_exec='uniq')


# This generates a test that checks that uniq works when given lines by cin
@max_score(25)
@dialog_exec(
    test_files / 'stdin_test1.dialog.txt', uniq_bin,
    close_stdin_after_all_inputs_given=True
)
def test_stdin1():
    ...


# This generates another test that checks that uniq works when given lines by
# cin
@max_score(25)
@dialog_exec(
    test_files / 'stdin_test2.dialog.txt', uniq_bin,
    close_stdin_after_all_inputs_given=True
)
def test_stdin2():
    ...


# This generates a test that checks that uniq works when given an input file to
# read from
@max_score(25)
@dialog_exec(
    test_files / 'file_test1.dialog.txt',
    uniq_bin, test_files / 'file_test1.input.txt'
)
def test_file1():
    ...


# This generates another test that checks that uniq works when given an input
# file to read from
@max_score(25)
@dialog_exec(
    test_files / 'file_test2.dialog.txt',
    uniq_bin, test_files / 'file_test2.input.txt'
)
def test_file2():
    ...
