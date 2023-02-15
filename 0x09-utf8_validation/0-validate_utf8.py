#!/usr/bin/python3
"""Utf-8 validation"""


def validUTF8(data: list) -> bool:
    """Validates a dataset"""
    byte_blocks = 0
    if not list:
        return False
    for i in data:
        if not byte_blocks:
            if i & 0b11110000 == 0b11110000:
                byte_blocks = 3
            elif i & 0b11100000 == 0b11100000:
                byte_blocks = 2
            elif i & 0b11000000 == 0b11000000:
                byte_blocks = 1
            elif i >> 7 != 0:
                return False
        else:
            if i >> 6 != 0b10:
                return False
            byte_blocks -= 1
    return byte_blocks == 0
