#!/usr/bin/python3
"""
Main for testing
"""

validUTF8 = __import__('0-validate_utf8').validUTF8
validUTF8_m = __import__('miguel').validUTF8
data = [467, 133, 108]
print(validUTF8(data))
print(validUTF8_m(data))