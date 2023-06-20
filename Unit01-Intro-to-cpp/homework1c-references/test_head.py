from byu_pytest_utils import cache, compile_cpp, dialog_exec, max_score, test_files


@cache
def head_bin():
    return compile_cpp('head.cpp', output_exec='head')


@max_score(10)
@dialog_exec(
    test_files / 'head_no_args.dialog.txt', head_bin,
    close_stdin_after_all_inputs_given=True
)
def test_no_arguments():
    ...


@max_score(10)
@dialog_exec(
    test_files / 'head_only_lines.dialog.txt', head_bin, '-7',
    close_stdin_after_all_inputs_given=True
)
def test_only_number_of_lines():
    ...


@max_score(10)
@dialog_exec(
    test_files / 'head_only_infile.dialog.txt',
    head_bin, test_files / 'head.input.txt'
)
def test_only_input_file():
    ...


@max_score(10)
@dialog_exec(
    test_files / 'head_both_args.dialog.txt',
    head_bin, '-13', test_files / 'head.input.txt'
)
def test_both_arguments():
    ...


@max_score(10)
@dialog_exec(
    test_files / 'head_not_enough_lines.dialog.txt',
    head_bin, '-20', test_files / 'head.input.txt'
)
def test_not_enough_lines():
    ...
