#!/usr/bin/python3
"""
Given a list of non-negative integers representing the heights of walls with
unit width 1, as if viewing the cross-section of a relief map, calculate
how many square units of water will be retained after it rains.
"""


def rain(walls: list) -> int:
    if not walls or len(walls) < 3:
        return 0

    n = len(walls)
    left = 0
    right = n-1
    l_max = 0
    r_max = 0
    result = 0
    while (left <= right):
        if r_max <= l_max:
            result += max(0, r_max - walls[right])
            r_max = max(r_max, walls[right])
            right -= 1
        else:
            result += max(0, l_max - walls[left])
            l_max = max(l_max, walls[left])
            left += 1
    return result


if __name__ == '__main__':
    rain(walls)
