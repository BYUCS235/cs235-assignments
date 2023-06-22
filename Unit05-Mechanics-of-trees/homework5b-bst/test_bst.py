from byu_pytest_utils import cache, compile_cpp, dialog_exec, max_score, test_files


# This compiles tests.cpp for all the tests to use
#
# See tests.cpp for a description of which functionality each test exercises
@cache
def bst_bin():
    return compile_cpp('*.cpp', output_exec='bst')


@max_score(10)
@dialog_exec(test_files / 'test1.dialog.txt', bst_bin, 1)
def test_1_insert_into_empty_tree():
    ...


@max_score(10)
@dialog_exec(test_files / 'test2.dialog.txt', bst_bin, 2)
def test_2_build_complex_tree():
    ...


@max_score(10)
@dialog_exec(test_files / 'test3.dialog.txt', bst_bin, 3)
def test_3_remove_leaf_node():
    ...


@max_score(10)
@dialog_exec(test_files / 'test4.dialog.txt', bst_bin, 4)
def test_4_remove_node_with_left_child():
    ...


@max_score(10)
@dialog_exec(test_files / 'test5.dialog.txt', bst_bin, 5)
def test_5_remove_node_with_right_child():
    ...


@max_score(10)
@dialog_exec(test_files / 'test6.dialog.txt', bst_bin, 6)
def test_6_remove_node_with_two_leaf_children():
    ...


@max_score(10)
@dialog_exec(test_files / 'test7.dialog.txt', bst_bin, 7)
def test_7_remove_node_with_two_subtrees():
    ...


@max_score(10)
@dialog_exec(test_files / 'test8.dialog.txt', bst_bin, 8)
def test_8_repeatedly_remove_root():
    ...


@max_score(10)
@dialog_exec(test_files / 'test9.dialog.txt', bst_bin, 9)
def test_9_contains():
    ...


@max_score(10)
@dialog_exec(test_files / 'test10.dialog.txt', bst_bin, 10)
def test_10_size_and_clear():
    ...
