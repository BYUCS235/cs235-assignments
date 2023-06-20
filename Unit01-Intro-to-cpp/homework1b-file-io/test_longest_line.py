from byu_pytest_utils import cache, compile_cpp, dialog_exec, max_score, test_files


@cache
def longest_line_bin():
    return compile_cpp('longest_line.cpp', output_exec='longest_line')


@max_score(25)
@dialog_exec(
    test_files / 'longest_line_test1.dialog.txt',
    longest_line_bin, test_files / 'longest_line_test1.input.txt'
)
def test_1():
    ...


@max_score(25)
@dialog_exec(
    test_files / 'longest_line_test2.dialog.txt',
    longest_line_bin, test_files / 'longest_line_test2.input.txt'
)
def test_2():
    ...
