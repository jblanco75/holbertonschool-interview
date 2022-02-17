#!/usr/bin/python3
"""
Method that determines if a given data
set represents a valid UTF-8 encoding
"""


def validUTF8(data):
    """
    Return: True if data is a valid UTF-8 encoding, else return False
    """
    n_bytes = 0

    byte_1 = 1 << 7
    byte_2 = 1 << 6

    for n in data:
        b = 1 << 7
        if n_bytes == 0:
            while b & n:
                n_bytes += 1
                b = b >> 1
            if n_bytes == 0:
                continue
            if n_bytes == 1 or n_bytes > 4:
                return False
        else:
            if not (n & byte_1 and not (n & byte_2)):
                return False
        n_bytes -= 1
    return n_bytes == 0
