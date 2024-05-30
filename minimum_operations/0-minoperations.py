#!/usr/bin/python3
"""Min operations"""


def minOperations(n):
    """Min operations"""
    if (n < 0 or not isinstance(n, int)):
        return 0
    ops = 0
    div = 2
    while(n > 1):
        if not(n % div):
            ops += div
            n /= div
            div = 2
        else:
            div += 1
    return ops
