from byu_pytest_utils import cache, compile_cpp, dialog_exec, max_score, test_files


@cache
def numbers_divisible_by_bin():
    return compile_cpp('numbers_divisible_by.cpp', output_exec='numbers_divisible_by')


@max_score(10)
@dialog_exec(test_files / 'ndb_going_up.dialog.txt', numbers_divisible_by_bin, 1, 10, 3)
def test_going_up():
    ...


@max_score(10)
@dialog_exec(test_files / 'ndb_going_down.dialog.txt', numbers_divisible_by_bin, 10, 1, 3)
def test_going_down():
    ...


@max_score(10)
@dialog_exec(test_files / 'ndb_includes_bounds_going_up.dialog.txt', numbers_divisible_by_bin, 2, 8, 2)
def test_includes_bounds_going_up():
    ...


@max_score(10)
@dialog_exec(test_files / 'ndb_includes_bounds_going_down.dialog.txt', numbers_divisible_by_bin, 16, 8, 4)
def test_includes_bounds_going_down():
    ...


@max_score(10)
@dialog_exec(test_files / 'ndb_negative_numbers_and_zero.dialog.txt', numbers_divisible_by_bin, -15, 15, 5)
def test_negative_numbers_and_zero():
    ...
