#!/usr/bin/python3
"""Test with unittest"""
import unittest
import pycodestyle
valid = __import__('0-making_change')


class TestDocs(unittest.TestCase):
    """
    A Class to check the documentation and style of 0-making_change
    """
    def test_pep8_validateUTF8(self):
        """Test PEP-8"""
        style = pycodestyle.StyleGuide(quite=True)
        result = style.check_files(['0-making_change.py'])
        self.assertEqual(result.total_errors, 0,
                         "Found code style errors (and warnings).")

    def test_pep8_main(self):
        """Test PEP-8"""
        style = pycodestyle.StyleGuide(quite=True)
        result = style.check_files(['0-main.py'])
        self.assertEqual(result.total_errors, 0,
                         "Found code style errors (and warnings).")

    def test_document(self):
        """Test Docstring of file"""
        self.assertIsNot(valid.__doc__, None,
                         "0-making_change needs a docstring")
        self.assertTrue(len(valid.__doc__) >= 1,
                        "0-making_change needs a docstring")

    def test_function(self):
        """Test Docstring of function"""
        self.assertIsNot(valid.makeChange.__doc__, None,
                         "making_change needs a docstring")
        self.assertTrue(len(valid.makeChange.__doc__) >= 1,
                        "making_change needs a docstring")
