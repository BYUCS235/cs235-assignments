from byu_pytest_utils import cache, compile_cpp, dialog_exec, max_score, test_files


# This compiles tests.cpp for all the tests to use
#
# See tests.cpp for a description of which functionality each test exercises
@cache
def find_bin():
    return compile_cpp('*.cpp', output_exec='find')


@max_score(25)
@dialog_exec(test_files / 'test1.dialog.txt', find_bin, 1)
def test_1_empty_tree():
    ...


@max_score(25)
@dialog_exec(test_files / 'test2.dialog.txt', find_bin, 2)
def test_2_line_going_right():
    ...


@max_score(25)
@dialog_exec(test_files / 'test3.dialog.txt', find_bin, 3)
def test_3_line_going_left():
    ...


@max_score(25)
@dialog_exec(test_files / 'test4.dialog.txt', find_bin, 4)
def test_4_balanced_tree():
    ...
