from byu_pytest_utils import cache, compile_cpp, dialog_exec, max_score, test_files


# This compiles tests.cpp for all the tests to use
#
# See tests.cpp for a description of which functionality each test exercises
@cache
def linked_list_bin():
    return compile_cpp('*.cpp', output_exec='linked_list')


@max_score(12.5)
@dialog_exec(test_files / 'test1.dialog.txt', linked_list_bin, 1)
def test_1_push_front_and_back():
    ...


@max_score(12.5)
@dialog_exec(test_files / 'test2.dialog.txt', linked_list_bin, 2)
def test_2_insert():
    ...


@max_score(12.5)
@dialog_exec(test_files / 'test3.dialog.txt', linked_list_bin, 3)
def test_3_front_and_back():
    ...


@max_score(12.5)
@dialog_exec(test_files / 'test4.dialog.txt', linked_list_bin, 4)
def test_4_at():
    ...


@max_score(12.5)
@dialog_exec(test_files / 'test5.dialog.txt', linked_list_bin, 5)
def test_5_contains():
    ...


@max_score(12.5)
@dialog_exec(test_files / 'test6.dialog.txt', linked_list_bin, 6)
def test_6_pop_front_and_back():
    ...


@max_score(12.5)
@dialog_exec(test_files / 'test7.dialog.txt', linked_list_bin, 7)
def test_7_remove():
    ...


@max_score(12.5)
@dialog_exec(test_files / 'test8.dialog.txt', linked_list_bin, 8)
def test_size_and_clear():
    ...
