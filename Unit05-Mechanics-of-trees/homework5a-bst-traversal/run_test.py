import json
from byu_pytest_utils import cache, compile_cpp, format_results_for_gradescope, run_exec, test_files, this_folder


@cache
def bst_find_bin():
    return compile_cpp('tests.cpp')

test_results = {
    'bst_find': [
        {
            'name': 'empty_tree',
            'points': 25,
            'result': run_exec(
                bst_find_bin, 1,
                expected_stdio=test_files / 'test1.stdout.txt'
            )
        },
        {
            'name': 'line_going_right',
            'points': 25,
            'result': run_exec(
                bst_find_bin, 2,
                expected_stdio=test_files / 'test2.stdout.txt'
            )
        },
        {
            'name': 'line_going_left',
            'points': 25,
            'result': run_exec(
                bst_find_bin, 3,
                expected_stdio=test_files / 'test3.stdout.txt'
            )
        },
        {
            'name': 'balanced_tree',
            'points': 25,
            'result': run_exec(
                bst_find_bin, 4,
                expected_stdio=test_files / 'test4.stdout.txt'
            )
        },
    ]
}

# print(json.dumps(test_results, indent=2))

results = format_results_for_gradescope(test_results)

with open('results.json', 'w') as file:
    json.dump(results, file, indent=2)
