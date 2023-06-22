from byu_pytest_utils import cache, compile_cpp, dialog_exec, max_score, test_files


# This compiles tests.cpp for all the tests to use
#
# See tests.cpp for a description of which functionality each test exercises
@cache
def avl_bin():
    return compile_cpp('*.cpp', output_exec='avl')


@max_score(2.5)
@dialog_exec(test_files / 'test1.dialog.txt', avl_bin, 1)
def test1_insert():
    ...


@max_score(2.5)
@dialog_exec(test_files / 'test2.dialog.txt', avl_bin, 2)
def test2_insert():
    ...


@max_score(3.75)
@dialog_exec(test_files / 'test3.dialog.txt', avl_bin, 3)
def test3_insert():
    ...


@max_score(3.75)
@dialog_exec(test_files / 'test4.dialog.txt', avl_bin, 4)
def test4_insert():
    ...


@max_score(3.75)
@dialog_exec(test_files / 'test5.dialog.txt', avl_bin, 5)
def test5_insert():
    ...


@max_score(3.75)
@dialog_exec(test_files / 'test6.dialog.txt', avl_bin, 6)
def test6_insert():
    ...


@max_score(7.5)
@dialog_exec(test_files / 'test7.dialog.txt', avl_bin, 7)
def test7_insert():
    ...


@max_score(7.5)
@dialog_exec(test_files / 'test8.dialog.txt', avl_bin, 8)
def test8_insert():
    ...


@max_score(7.5)
@dialog_exec(test_files / 'test9.dialog.txt', avl_bin, 9)
def test9_insert():
    ...


@max_score(7.5)
@dialog_exec(test_files / 'test10.dialog.txt', avl_bin, 10)
def test10_insert():
    ...


@max_score(2.5)
@dialog_exec(test_files / 'test11.dialog.txt', avl_bin, 11)
def test11_contains():
    ...


@max_score(7.5)
@dialog_exec(test_files / 'test12.dialog.txt', avl_bin, 12)
def test12_remove():
    ...


@max_score(7.5)
@dialog_exec(test_files / 'test13.dialog.txt', avl_bin, 13)
def test13_remove():
    ...


@max_score(7.5)
@dialog_exec(test_files / 'test14.dialog.txt', avl_bin, 14)
def test14_remove():
    ...


@max_score(7.5)
@dialog_exec(test_files / 'test15.dialog.txt', avl_bin, 15)
def test15_remove():
    ...


@max_score(10)
@dialog_exec(test_files / 'test16.dialog.txt', avl_bin, 16)
def test16_repeatedly_remove_root_node():
    ...


@max_score(5)
@dialog_exec(test_files / 'test17.dialog.txt', avl_bin, 17)
def test17_remove_then_insert():
    ...


@max_score(2.5)
@dialog_exec(test_files / 'test18.dialog.txt', avl_bin, 18)
def test18_size_and_clear():
    ...
