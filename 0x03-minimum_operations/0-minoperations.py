#!/usr/bin/python3
"""
Method that calculates the fewest number of operations
needed to result in exactly n H characters in the file
"""


def minOperations(n):
    """
    Method that calculates the
    fewest number of operations needed
    """
    if type(n) is not int or n < 2:
        return 0
    operations = 0
    count = 2
    while (count < n + 1):
        while n % count == 0:
            operations += count
            n /= count
        count += 1
    return operations
