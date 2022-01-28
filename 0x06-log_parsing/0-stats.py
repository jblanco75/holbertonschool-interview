#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics
"""


from sys import stdin


def print_stats(file_size, status_codes):
    """Prints file size and codes"""
    print("File size: {}".format(file_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] != 0:
            print("{}: {}".format(code, status_codes[code]))


count = file_size = currentCode = 0
status_codes = {
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0
}

try:
    for line in stdin:
        count += 1
        currentLine = line.split()

        if currentLine[-1].isnumeric():
            file_size += int(currentLine[-1])

        if len(currentLine) > 2 and currentLine[-2] in status_codes:
            status_codes[currentLine[-2]] += 1

        if count % 10 == 0:
            print_stats(file_size, status_codes)

    print_stats(file_size, status_codes)

except (KeyboardInterrupt):
    print_stats(file_size, status_codes)
