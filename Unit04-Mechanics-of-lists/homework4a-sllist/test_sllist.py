from byu_pytest_utils import cache, compile_cpp, dialog_exec, max_score, test_files


# This compiles tests.cpp for all the tests to use
#
# See tests.cpp for a description of which functionality each test exercises
@cache
def linked_list_bin():
    return compile_cpp('*.cpp', output_exec='linked_list')


@max_score(30)
@dialog_exec(test_files / 'test1.dialog.txt', linked_list_bin, 1)
def test_1_push_back():
    ...


@max_score(30)
@dialog_exec(test_files / 'test2.dialog.txt', linked_list_bin, 2)
def test_2_pop_back():
    ...


@max_score(20)
@dialog_exec(test_files / 'test3.dialog.txt', linked_list_bin, 3)
def test_3_front():
    ...


@max_score(20)
@dialog_exec(test_files / 'test4.dialog.txt', linked_list_bin, 4)
def test_4_size_and_clear():
    ...
