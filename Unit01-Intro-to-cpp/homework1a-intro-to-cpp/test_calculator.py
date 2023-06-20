from byu_pytest_utils import cache, compile_cpp, dialog_exec, max_score, test_files


@cache
def calculator_bin():
    return compile_cpp('calculator.cpp', output_exec='calculator')


@max_score(8.33)
@dialog_exec(test_files / 'calc_add.dialog.txt', calculator_bin)
def test_add():
    ...


@max_score(8.33)
@dialog_exec(test_files / 'calc_subtract.dialog.txt', calculator_bin)
def test_subtract():
    ...


@max_score(8.33)
@dialog_exec(test_files / 'calc_multiply.dialog.txt', calculator_bin)
def test_multiply():
    ...


@max_score(8.33)
@dialog_exec(test_files / 'calc_divide.dialog.txt', calculator_bin)
def test_divide():
    ...


@max_score(8.33)
@dialog_exec(test_files / 'calc_mod.dialog.txt', calculator_bin)
def test_mod():
    ...


@max_score(8.35)
@dialog_exec(test_files / 'calc_invalid_operation.dialog.txt', calculator_bin)
def test_invalid_operation():
    ...
