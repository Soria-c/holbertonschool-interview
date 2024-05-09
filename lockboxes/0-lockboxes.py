#!/usr/bin/python3
"""Lockboxes"""


def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened."""
    box_len = len(boxes)
    keys = set({0, *boxes[0]})
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
