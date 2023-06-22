from byu_pytest_utils import cache, compile_cpp, dialog_exec, max_score, test_files


# This compiles pqueues.cpp for all the tests to use
@cache
def pqueues_bin():
    return compile_cpp('*.cpp', output_exec='pqueues')


# This generates a simple test that checks that pqueues works
@max_score(50)
@dialog_exec(test_files / 'test1.dialog.txt', pqueues_bin)
def test_1():
    ...


# This generates a more complex test that adds new people after taking some out
# of the queue
@max_score(50)
@dialog_exec(test_files / 'test2.dialog.txt', pqueues_bin)
def test_2():
    ...
