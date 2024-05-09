#!/usr/bin/python3
"""Lockboxes"""


def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened."""

    visited = {}
    len_v = len(visited)
    rem_boxes = len(boxes) - 1
    keys = set(boxes[0])
    total_keys = keys

    while(len_v != rem_boxes):
        k = set()
        for i in keys:
            if (i and i < (rem_boxes + 1)):
                k = k.union(set(boxes[i]))
                visited[str(i)] = True
        if (len(visited) == len_v):
            break
        len_v = len(visited)
        keys = k.difference(total_keys) - {0}
        total_keys = total_keys.union(keys)

    return len_v == rem_boxes
