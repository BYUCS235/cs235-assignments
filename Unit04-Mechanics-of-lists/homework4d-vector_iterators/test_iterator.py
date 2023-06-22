from byu_pytest_utils import cache, compile_cpp, dialog_exec, max_score, test_files


# This compiles tests.cpp for all the tests to use
#
# See tests.cpp for a description of which functionality each test exercises
@cache
def iterator_bin():
    return compile_cpp('*.cpp', output_exec='iterator')


@max_score(50)
@dialog_exec(test_files / 'test1.dialog.txt', iterator_bin, 1)
def test_1():
    ...


@max_score(50)
@dialog_exec(test_files / 'test2.dialog.txt', iterator_bin, 2)
def test_2():
    ...
