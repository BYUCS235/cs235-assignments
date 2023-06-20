from byu_pytest_utils import cache, compile_cpp, dialog_exec, max_score, test_files


@cache
def pqueues_bin():
    return compile_cpp('*.cpp', output_exec='pqueues')


@max_score(50)
@dialog_exec(test_files / 'test1.dialog.txt', pqueues_bin)
def test_1():
    ...


@max_score(50)
@dialog_exec(test_files / 'test2.dialog.txt', pqueues_bin)
def test_2():
    ...
