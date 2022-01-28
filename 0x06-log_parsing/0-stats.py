#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics
"""


from sys import stdin


codes = {
        "200": 0,
        "301": 0,
        "400": 0,
        "401": 0,
        "403": 0,
        "404": 0,
        "405": 0,
        "500": 0
}

size = 0
i = 0


def statprinter():
    """
    Prints accumulated logs
    """
    print('File size: {}'.format(int(size)))
    for status_code, value in codes.items():
        if value == 0:
            continue

        print('{}: {}'.format(status_code, value))


if __name__ == "__main__":

    try:
        while True:
            current_line = stdin.readline().strip()
            tokens = current_line.split(' ')

            if len(tokens) != 9:
                pass

            current_size, status_code = tokens[-1], tokens[-2]
            size += float(current_size)
            codes[status_code] += 1
            i += 1

            if i == 10:
                statprinter()
                i = 0
    except KeyboardInterrupt:
        statprinter()
        raise
    statprinter()
