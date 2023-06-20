from byu_pytest_utils import cache, compile_cpp, dialog_exec, max_score, test_files


@cache
def sort_bin():
    return compile_cpp('sort.cpp', output_exec='sort')


@max_score(12.5)
@dialog_exec(
    test_files / 'sort_test1.dialog.txt', sort_bin,
    'exalt', 'egregious', 'indomitable'
)
def test_1():
    ...


@max_score(12.5)
@dialog_exec(
    test_files / 'sort_test2.dialog.txt', sort_bin,
    'clamor', 'furtive', 'chicanery'
)
def test_2():
    ...


@max_score(12.5)
@dialog_exec(
    test_files / 'sort_test3.dialog.txt', sort_bin,
    'deluge', 'clamor', 'cacophony'
)
def test_3():
    ...


@max_score(12.5)
@dialog_exec(
    test_files / 'sort_test4.dialog.txt', sort_bin,
    'multifarious', 'empathy', 'euphoria'
)
def test_4():
    ...
