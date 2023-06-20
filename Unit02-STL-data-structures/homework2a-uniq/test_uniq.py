from byu_pytest_utils import cache, compile_cpp, dialog_exec, max_score, test_files


@cache
def uniq_bin():
    return compile_cpp('*.cpp', output_exec='uniq')


@max_score(25)
@dialog_exec(
    test_files / 'stdin_test1.dialog.txt', uniq_bin,
    close_stdin_after_all_inputs_given=True
)
def test_stdin1():
    ...


@max_score(25)
@dialog_exec(
    test_files / 'stdin_test2.dialog.txt', uniq_bin,
    close_stdin_after_all_inputs_given=True
)
def test_stdin2():
    ...


@max_score(25)
@dialog_exec(
    test_files / 'file_test1.dialog.txt',
    uniq_bin, test_files / 'file_test1.input.txt'
)
def test_file1():
    ...


@max_score(25)
@dialog_exec(
    test_files / 'file_test2.dialog.txt',
    uniq_bin, test_files / 'file_test2.input.txt'
)
def test_file2():
    ...
