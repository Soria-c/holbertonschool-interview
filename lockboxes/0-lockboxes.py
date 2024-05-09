#!/usr/bin/python3
"""This module contains the function canUnlockAll
    which is a method that determines if all the boxes
    can be opened.
"""


def canUnlockAll(boxes):
    """
    Method that determines if all the boxes can be opened.
    ```
    Parameters:
    -----------
    boxes: list[][]
        boxes is a list of lists
    """
    box_len = len(boxes)
    keys = set({0}).union(filter(lambda x: x < box_len, boxes[0]))
    i = 1
    while i < box_len - 1 and len(keys) != box_len:
        if i in keys:
            for j in boxes[i]:
                if j < box_len:
                    keys.add(j)
                    keys = keys.union(filter(lambda x: x < box_len, boxes[j]))
                if (len(keys) == box_len):
                    break
        i += 1
    return len(keys) == box_len
