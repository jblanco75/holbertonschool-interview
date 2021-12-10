#!/usr/bin/python3
"""Function that determines if all the boxes can be opened"""


def canUnlockAll(boxes):
    """Returns True if all boxes can be opened"""
    if type(boxes) is not list:
        return False
    if len(boxes) == 0:
        return False
    open_box = [0]
    for box in open_box:
        for key in boxes[box]:
            if key not in open_box and key < len(boxes):
                open_box.append(key)
    if len(open_box) == len(boxes):
        return True
    else:
        return False
