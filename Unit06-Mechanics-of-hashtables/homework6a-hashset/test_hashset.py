from byu_pytest_utils import cache, compile_cpp, dialog_exec, max_score, test_files


# This compiles tests.cpp for all the tests to use
#
# See tests.cpp for a description of which functionality each test exercises
@cache
def hashset_bin():
    return compile_cpp('*.cpp', output_exec='hashset')


@max_score(20)
@dialog_exec(test_files / 'test1.dialog.txt', hashset_bin, 1)
def test1_insert():
    ...


@max_score(20)
@dialog_exec(test_files / 'test2.dialog.txt', hashset_bin, 2)
def test2_contains():
    ...


@max_score(20)
@dialog_exec(test_files / 'test3.dialog.txt', hashset_bin, 3)
def test3_remove():
    ...


@max_score(10)
@dialog_exec(test_files / 'test4.dialog.txt', hashset_bin, 4)
def test4_size_and_clear():
    ...


@max_score(30)
@dialog_exec(test_files / 'test5.dialog.txt', hashset_bin, 5)
def test5_rehashing_stress_test():
    ...
