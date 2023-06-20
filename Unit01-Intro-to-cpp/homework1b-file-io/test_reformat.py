from byu_pytest_utils import cache, compile_cpp, dialog_exec, max_score, test_files


@cache
def reformat_bin():
    return compile_cpp('reformat.cpp', output_exec='reformat')


@max_score(25)
@dialog_exec(
    test_files / 'reformat_test1.dialog.txt', reformat_bin,
    test_files / 'reformat_test1.input.txt', 'reformat_test1.output.txt',
    output_file='reformat_test1.output.txt'
)
def test_1():
    ...


@max_score(25)
@dialog_exec(
    test_files / 'reformat_test2.dialog.txt', reformat_bin,
    test_files / 'reformat_test2.input.txt', 'reformat_test2.output.txt',
    output_file='reformat_test2.output.txt'
)
def test_2():
    ...
