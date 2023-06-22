from byu_pytest_utils import cache, compile_cpp, dialog_exec, max_score, test_files


# This compiles tests.cpp for all the tests to use
#
# See tests.cpp for a description of which functionality each test exercises
@cache
def vector_set_bin():
    return compile_cpp('*.cpp', output_exec='VectorSet')


@max_score(25)
@dialog_exec(test_files / 'test1.dialog.txt', vector_set_bin, 1)
def test_1_insert_and_contains():
    ...


@max_score(25)
@dialog_exec(test_files / 'test2.dialog.txt', vector_set_bin, 2)
def test_2_remove():
    ...


@max_score(25)
@dialog_exec(test_files / 'test3.dialog.txt', vector_set_bin, 3)
def test_3_empty_and_size():
    ...


@max_score(25)
@dialog_exec(test_files / 'test4.dialog.txt', vector_set_bin, 4)
def test_4_clear():
    ...
