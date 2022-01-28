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


def statprinter():
    """
    Prints accumulated logs
    """
    print("File size: {}".format(size))
    for stat in sorted(codes.keys()):
        if codes[stat]:
            print("{}: {}".format(stat, codes[stat]))


if __name__ == "__main__":
    count = 0
    try:
        for _input in stdin:
            try:
                items = _input.split()
                size += int(items[-1])
                if items[-2] in codes:
                    codes[items[-2]] += 1
            except:
                pass
            if count == 9:
                statprinter()
                count = -1
                count += 1
    except KeyboardInterrupt:
        statprinter()
        raise
    statprinter()
