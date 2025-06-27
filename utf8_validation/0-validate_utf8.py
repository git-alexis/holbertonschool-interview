#!/usr/bin/python3
"""
ValidUTF8 Module
"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding.
    """
    byte_sequence = bytes([number & 0xFF for number in data])
    try:
        byte_sequence.decode('utf-8')
        return True
    except UnicodeDecodeError:
        return False
