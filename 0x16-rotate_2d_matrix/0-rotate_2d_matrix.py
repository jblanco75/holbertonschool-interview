#!/usr/bin/python3
"""
Function that rotates a 2D matrix
"""


def rotate_2d_matrix(matrix):
    """
    Rotates a matrix 90 degrees
    """
    copy = list(zip(*matrix[::-1]))
    i = len(matrix)
    j = len(matrix[0])
    for v in range(i):
        for e in range(j):
            matrix[v][e] = copy[v][e]
