#!/usr/bin/python3
"""Lockboxes"""


def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened."""

    visited = {}
    len_v = len(visited)
    rem_boxes = len(boxes) - 1
    keys = set(boxes[0])
    total_keys = keys
    final_len_v = 0

    while(len_v != rem_boxes):
        k = set()
        for i in keys:
            if (i and i < (rem_boxes + 1)):
                k = k.union(set(boxes[i]))
                index = str(i)
                if (not visited.get(index)):
                    visited[index] = True
        final_len_v = len(visited)
        if (final_len_v  == len_v):
            break
        len_v = final_len_v 
        keys = k.difference(total_keys)
        total_keys = total_keys.union(keys)

    return final_len_v  == rem_boxes
