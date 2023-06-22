from byu_pytest_utils import cache, compile_cpp, dialog_exec, max_score, test_files


# This compiles tests.cpp for all the tests to use
#
# See tests.cpp for a description of which functionality each test exercises
@cache
def quicksort_bin():
    return compile_cpp('tests.cpp', output_exec='tests')


@max_score(10)
@dialog_exec(test_files / 'test1.dialog.txt', quicksort_bin, 1)
def test_1_medianOfThree():
    ...


@max_score(15)
@dialog_exec(test_files / 'test2.dialog.txt', quicksort_bin, 2)
def test_2_partition_already_sorted():
    ...


@max_score(15)
@dialog_exec(test_files / 'test3.dialog.txt', quicksort_bin, 3)
def test_3_partition_reversed():
    ...


@max_score(15)
@dialog_exec(test_files / 'test4.dialog.txt', quicksort_bin, 4)
def test_4_partition_shuffled():
    ...


@max_score(15)
@dialog_exec(test_files / 'test5.dialog.txt', quicksort_bin, 5)
def test_5_sort_already_sorted():
    ...


@max_score(15)
@dialog_exec(test_files / 'test6.dialog.txt', quicksort_bin, 6)
def test_6_sort_reversed():
    ...


@max_score(15)
@dialog_exec(test_files / 'test7.dialog.txt', quicksort_bin, 7)
def test_7_sort_shuffled():
    ...
