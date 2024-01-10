import json
from byu_pytest_utils import cache, compile_cpp, format_results_for_gradescope, run_exec, test_files, this_folder


@cache
def bst_bin():
    return compile_cpp('tests.cpp')

test_results = {
    'bst': [
        {
            'name': 'insert_into_empty_tree',
            'points': 10,
            'result': run_exec(
                bst_bin, 1,
                expected_stdio=test_files / 'test1.stdout.txt'
            )
        },
        {
            'name': 'build_complex_tree',
            'points': 10,
            'result': run_exec(
                bst_bin, 2,
                expected_stdio=test_files / 'test2.stdout.txt'
            )
        },
        {
            'name': 'remove_leaf_node',
            'points': 10,
            'result': run_exec(
                bst_bin, 3,
                expected_stdio=test_files / 'test3.stdout.txt'
            )
        },
        {
            'name': 'remove_node_with_left_child',
            'points': 10,
            'result': run_exec(
                bst_bin, 4,
                expected_stdio=test_files / 'test4.stdout.txt'
            )
        },
        {
            'name': 'remove_node_with_right_child',
            'points': 10,
            'result': run_exec(
                bst_bin, 5,
                expected_stdio=test_files / 'test5.stdout.txt'
            )
        },
        {
            'name': 'remove_node_with_two_leaf_children',
            'points': 10,
            'result': run_exec(
                bst_bin, 6,
                expected_stdio=test_files / 'test6.stdout.txt'
            )
        },
        {
            'name': 'remove_node_with_two_subtrees',
            'points': 10,
            'result': run_exec(
                bst_bin, 7,
                expected_stdio=test_files / 'test7.stdout.txt'
            )
        },
        {
            'name': 'repeatedly_remove_root',
            'points': 10,
            'result': run_exec(
                bst_bin, 8,
                expected_stdio=test_files / 'test8.stdout.txt'
            )
        },
        {
            'name': 'contains',
            'points': 10,
            'result': run_exec(
                bst_bin, 9,
                expected_stdio=test_files / 'test9.stdout.txt'
            )
        },
        {
            'name': 'size_and_clear',
            'points': 10,
            'result': run_exec(
                bst_bin, 10,
                expected_stdio=test_files / 'test10.stdout.txt'
            )
        },
    ]
}

# print(json.dumps(test_results, indent=2))

results = format_results_for_gradescope(test_results)

with open('results.json', 'w') as file:
    json.dump(results, file, indent=2)
