from byu_pytest_utils import cache, compile_cpp, dialog_exec, max_score, test_files


# This compiles head.cpp for all the tests to use
@cache
def head_bin():
    return compile_cpp('head.cpp', output_exec='head')


# This generates a test that checks that head works when given no program
# arguments
@max_score(10)
@dialog_exec(
    test_files / 'head_no_args.dialog.txt', head_bin,
    close_stdin_after_all_inputs_given=True
)
def test_no_arguments():
    ...


# This generates a test that checks that head works when only given a number of
# lines to output
@max_score(10)
@dialog_exec(
    test_files / 'head_only_lines.dialog.txt', head_bin, '-7',
    close_stdin_after_all_inputs_given=True
)
def test_only_number_of_lines():
    ...


# This generates a test that checks that head works when only given an input
# file
@max_score(10)
@dialog_exec(
    test_files / 'head_only_infile.dialog.txt',
    head_bin, test_files / 'head.input.txt'
)
def test_only_input_file():
    ...


# This generates a test that checks that head works when given both a number of
# lines and an input file
@max_score(10)
@dialog_exec(
    test_files / 'head_both_args.dialog.txt',
    head_bin, '-13', test_files / 'head.input.txt'
)
def test_both_arguments():
    ...


# This generates a test that checks that head will function properly when asked
# to output more lines than the input file has
@max_score(10)
@dialog_exec(
    test_files / 'head_not_enough_lines.dialog.txt',
    head_bin, '-20', test_files / 'head.input.txt'
)
def test_not_enough_lines():
    ...
