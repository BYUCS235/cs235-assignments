from byu_pytest_utils import cache, compile_cpp, dialog_exec, max_score, test_files


# This compiles numbers_divisible_by.cpp for all the tests to use
@cache
def numbers_divisible_by_bin():
    return compile_cpp('numbers_divisible_by.cpp', output_exec='numbers_divisible_by')


# This generates a test that checks numbers_divisible_by's functionality when
# ending at a greater number than the starting number
@max_score(10)
@dialog_exec(test_files / 'ndb_going_up.dialog.txt', numbers_divisible_by_bin, 1, 10, 3)
def test_going_up():
    ...


# This generates a test that checks numbers_divisible_by's functionality when
# ending at a lesser number than the starting number
@max_score(10)
@dialog_exec(test_files / 'ndb_going_down.dialog.txt', numbers_divisible_by_bin, 10, 1, 3)
def test_going_down():
    ...


# This generates a test that checks numbers_divisible_by's functionality when
# ending at a greater number than the starting number, but where both bounds are
# divisible by the divisor
@max_score(10)
@dialog_exec(test_files / 'ndb_includes_bounds_going_up.dialog.txt', numbers_divisible_by_bin, 2, 8, 2)
def test_includes_bounds_going_up():
    ...


# This generates a test that checks numbers_divisible_by's functionality when
# ending at a lesser number than the starting number, but where both bounds are
# divisible by the divisor
@max_score(10)
@dialog_exec(test_files / 'ndb_includes_bounds_going_down.dialog.txt', numbers_divisible_by_bin, 16, 8, 4)
def test_includes_bounds_going_down():
    ...


# This generates a test that checks that numbers_divisible_by can properly
# include negative numbers that are divisible by the divisor (as well as that it
# can include 0)
@max_score(10)
@dialog_exec(test_files / 'ndb_negative_numbers_and_zero.dialog.txt', numbers_divisible_by_bin, -15, 15, 5)
def test_negative_numbers_and_zero():
    ...
