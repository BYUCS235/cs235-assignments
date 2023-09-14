from byu_pytest_utils import dialog, forbid_header


@pytest.fixture
def exec_name(): 
    forbid_header("calc.cpp", "algorithm")
    # compile the executable
    return "calc"


@dialog_exec(
        "test_files/calc_add.dialog.txt",
        "add", 1, 2
)
def test_calc_add(exec_name): ...