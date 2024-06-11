def prod(a: int, b: int):
    for i in range(a):
        for j in range(b):
            yield i, j


def main(a: int, b: int):
    for pair in prod(a, b):
        print(pair)


if __name__ == '__main__':
    import sys
    main(int(sys.argv[1]), int(sys.argv[2]))
    