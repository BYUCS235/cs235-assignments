from byu_pytest_utils import cache, compile_cpp, dialog_exec, max_score, test_files


# This compiles tests.cpp for all the tests to use
#
# See tests.cpp for a description of which functionality each test exercises
@cache
def vector_bin():
    return compile_cpp('*.cpp', output_exec='vector')


@max_score(15)
@dialog_exec(test_files / 'test1.dialog.txt', vector_bin, 1)
def test_1_push_back():
    ...


@max_score(17)
@dialog_exec(test_files / 'test2.dialog.txt', vector_bin, 2)
def test_2_insert():
    ...


@max_score(15)
@dialog_exec(test_files / 'test3.dialog.txt', vector_bin, 3)
def test_3_operator_brackets():
    ...


@max_score(15)
@dialog_exec(test_files / 'test4.dialog.txt', vector_bin, 4)
def test_4_remove():
    ...


@max_score(18)
@dialog_exec(test_files / 'test5.dialog.txt', vector_bin, 5)
def test_5_size_and_clear():
    ...


@max_score(20)
@dialog_exec(test_files / 'test6.dialog.txt', vector_bin, 6)
def test_6_growing():
    ...
