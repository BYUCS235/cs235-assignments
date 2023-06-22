from byu_pytest_utils import cache, compile_cpp, dialog_exec, max_score, test_files


# This compiles tests.cpp for all the tests to use
#
# See tests.cpp for a description of which functionality each test exercises
@cache
def rebalance_bin():
    return compile_cpp('*.cpp', output_exec='rebalance')


@max_score(5)
@dialog_exec(test_files / 'test1.dialog.txt', rebalance_bin, 1)
def test_1_promote_left_with_two_nodes():
    ...


@max_score(7)
@dialog_exec(test_files / 'test2.dialog.txt', rebalance_bin, 2)
def test_2_promote_left_with_tree():
    ...


@max_score(5)
@dialog_exec(test_files / 'test3.dialog.txt', rebalance_bin, 3)
def test_3_promote_right_with_two_nodes():
    ...


@max_score(7)
@dialog_exec(test_files / 'test4.dialog.txt', rebalance_bin, 4)
def test_4_promote_right_with_tree():
    ...


@max_score(5)
@dialog_exec(test_files / 'test5.dialog.txt', rebalance_bin, 5)
def test_5_rebalance_leaf_nodes():
    ...


@max_score(5)
@dialog_exec(test_files / 'test6.dialog.txt', rebalance_bin, 6)
def test_6_rebalance_balanced_tree():
    ...


@max_score(15)
@dialog_exec(test_files / 'test7.dialog.txt', rebalance_bin, 7)
def test_7_rebalance_ll_imbalance():
    ...


@max_score(15)
@dialog_exec(test_files / 'test8.dialog.txt', rebalance_bin, 8)
def test_8_rebalance_rr_imbalance():
    ...


@max_score(18)
@dialog_exec(test_files / 'test9.dialog.txt', rebalance_bin, 9)
def test_9_rebalance_lr_imbalance():
    ...


@max_score(18)
@dialog_exec(test_files / 'test10.dialog.txt', rebalance_bin, 10)
def test_10_rebalance_rl_imbalance():
    ...
