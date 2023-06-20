from byu_pytest_utils import cache, compile_cpp, dialog_exec, max_score, test_files


@cache
def sort_bin():
    return compile_cpp('*.cpp', output_exec='sort')


@max_score(25)
@dialog_exec(
    test_files / 'test1.dialog.txt',
    sort_bin, test_files / 'test1.input.txt'
)
def test_1_already_sorted():
    ...


@max_score(25)
@dialog_exec(
    test_files / 'test2.dialog.txt',
    sort_bin, test_files / 'test2.input.txt'
)
def test_2_reversed():
    ...


@max_score(25)
@dialog_exec(
    test_files / 'test3.dialog.txt',
    sort_bin, test_files / 'test3.input.txt'
)
def test_3_shuffled():
    ...


@max_score(25)
@dialog_exec(
    test_files / 'test4.dialog.txt', sort_bin,
    close_stdin_after_all_inputs_given=True
)
def test_4_stdin():
    ...
