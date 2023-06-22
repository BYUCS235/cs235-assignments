from byu_pytest_utils import cache, compile_cpp, dialog_exec, max_score, test_files


# This compiles calculator.cpp for all the tests to use
@cache
def calculator_bin():
    return compile_cpp('calculator.cpp', output_exec='calculator')


# This generates a test that checks the calculator's add operation
@max_score(8.33)
@dialog_exec(test_files / 'calc_add.dialog.txt', calculator_bin)
def test_add():
    ...


# This generates a test that checks the calculator's subtract operation
@max_score(8.33)
@dialog_exec(test_files / 'calc_subtract.dialog.txt', calculator_bin)
def test_subtract():
    ...


# This generates a test that checks the calculator's multiply operation
@max_score(8.33)
@dialog_exec(test_files / 'calc_multiply.dialog.txt', calculator_bin)
def test_multiply():
    ...


# This generates a test that checks the calculator's divide operation
@max_score(8.33)
@dialog_exec(test_files / 'calc_divide.dialog.txt', calculator_bin)
def test_divide():
    ...


# This generates a test that checks the calculator's mod operation
@max_score(8.33)
@dialog_exec(test_files / 'calc_mod.dialog.txt', calculator_bin)
def test_mod():
    ...


# This generates a test that checks the calculator's response to an invalid
# operation
@max_score(8.35)
@dialog_exec(test_files / 'calc_invalid_operation.dialog.txt', calculator_bin)
def test_invalid_operation():
    ...
