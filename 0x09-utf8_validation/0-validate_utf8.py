#!/usr/bin/python3
"""Utf-8 validation"""

from typing import List


def validUTF8(data: List[int]) -> bool:
    """Validates a dataset"""
    byte_blocks = 0
    for i in data:
        if not byte_blocks:
            if i >> 3 == 0b11110:
                byte_blocks = 3
            elif i >> 4 == 0b1110:
                byte_blocks = 2
            elif i >> 5 == 0b110:
                byte_blocks = 1
            elif i >> 7 != 0:
                return False
        else:
            if i >> 6 != 0b10:
                return False
            byte_blocks -= 1
    return byte_blocks == 0
