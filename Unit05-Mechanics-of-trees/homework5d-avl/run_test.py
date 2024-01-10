import json
from byu_pytest_utils import cache, compile_cpp, format_results_for_gradescope, run_exec, test_files, this_folder


@cache
def avl_bin():
    return compile_cpp('tests.cpp')

test_results = {
    'avl': [
        {
            'name': 'insert1',
            'points': 2.5,
            'result': run_exec(
                avl_bin, 1,
                expected_stdio=test_files / 'test1.stdout.txt'
            )
        },
        {
            'name': 'insert2',
            'points': 2.5,
            'result': run_exec(
                avl_bin, 2,
                expected_stdio=test_files / 'test2.stdout.txt'
            )
        },
        {
            'name': 'insert3',
            'points': 3.75,
            'result': run_exec(
                avl_bin, 3,
                expected_stdio=test_files / 'test3.stdout.txt'
            )
        },
        {
            'name': 'insert4',
            'points': 3.75,
            'result': run_exec(
                avl_bin, 4,
                expected_stdio=test_files / 'test4.stdout.txt'
            )
        },
        {
            'name': 'insert5',
            'points': 3.75,
            'result': run_exec(
                avl_bin, 5,
                expected_stdio=test_files / 'test5.stdout.txt'
            )
        },
        {
            'name': 'insert6',
            'points': 3.75,
            'result': run_exec(
                avl_bin, 6,
                expected_stdio=test_files / 'test6.stdout.txt'
            )
        },
        {
            'name': 'insert7',
            'points': 7.5,
            'result': run_exec(
                avl_bin, 7,
                expected_stdio=test_files / 'test7.stdout.txt'
            )
        },
        {
            'name': 'insert8',
            'points': 7.5,
            'result': run_exec(
                avl_bin, 8,
                expected_stdio=test_files / 'test8.stdout.txt'
            )
        },
        {
            'name': 'insert9',
            'points': 7.5,
            'result': run_exec(
                avl_bin, 9,
                expected_stdio=test_files / 'test9.stdout.txt'
            )
        },
        {
            'name': 'insert10',
            'points': 7.5,
            'result': run_exec(
                avl_bin, 10,
                expected_stdio=test_files / 'test10.stdout.txt'
            )
        },
        {
            'name': 'contains',
            'points': 2.5,
            'result': run_exec(
                avl_bin, 11,
                expected_stdio=test_files / 'test11.stdout.txt'
            )
        },
        {
            'name': 'remove1',
            'points': 7.5,
            'result': run_exec(
                avl_bin, 12,
                expected_stdio=test_files / 'test12.stdout.txt'
            )
        },
        {
            'name': 'remove2',
            'points': 7.5,
            'result': run_exec(
                avl_bin, 13,
                expected_stdio=test_files / 'test13.stdout.txt'
            )
        },
        {
            'name': 'remove3',
            'points': 7.5,
            'result': run_exec(
                avl_bin, 14,
                expected_stdio=test_files / 'test14.stdout.txt'
            )
        },
        {
            'name': 'remove4',
            'points': 7.5,
            'result': run_exec(
                avl_bin, 15,
                expected_stdio=test_files / 'test15.stdout.txt'
            )
        },
        {
            'name': 'repeatedly_remove_root_node',
            'points': 10,
            'result': run_exec(
                avl_bin, 16,
                expected_stdio=test_files / 'test16.stdout.txt'
            )
        },
        {
            'name': 'remove_then_insert',
            'points': 5,
            'result': run_exec(
                avl_bin, 17,
                expected_stdio=test_files / 'test17.stdout.txt'
            )
        },
        {
            'name': 'size_and_clear',
            'points': 2.5,
            'result': run_exec(
                avl_bin, 18,
                expected_stdio=test_files / 'test18.stdout.txt'
            )
        }
    ]
}

# print(json.dumps(test_results, indent=2))

results = format_results_for_gradescope(test_results)

with open('results.json', 'w') as file:
    json.dump(results, file, indent=2)
