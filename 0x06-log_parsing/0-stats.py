#!/usr/bin/python3
"""
This module defines the functions:
    print_data()
"""
from sys import stdin, exit
import signal


status_code = {"200": 0, "301": 0, "400": 0, "401": 0,
               "403": 0, "404": 0, "405": 0, "500": 0}
count = 0
total_size = 0


def print_data(signal=None, frame=None):
    """Prints statistics data"""
    print(f"File size: {total_size}")
    for j, k in sorted(status_code.items()):
        if (k):
            print(f"{j}: {k}")
    if (signal and frame):
        exit(0)


signal.signal(signal.SIGINT, print_data)

for i in stdin:
    count += 1
    line = i.strip("\n").split(" ")
    if (len(line) == 1):
        continue
    total_size += int(line[-1])
    if line[-2] in status_code:
        status_code[line[-2]] += 1
    if count == 10:
        print_data()
        count = 0
print_data()
