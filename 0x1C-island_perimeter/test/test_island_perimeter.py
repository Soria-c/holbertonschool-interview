#!/usr/bin/python3
"""Test with unittest"""
import unittest
import pycodestyle

file = '0-island_perimeter'
valid = __import__(file)


class TestDocs(unittest.TestCase):
    """
    A Class to check the documentation and style of 0-validate_utf8
    """

    def test_pep8_island_perimeter(self):
        """Test PEP-8"""
        style = pycodestyle.StyleGuide(quite=True)
        result = style.check_files([file + '.py'])
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
                         "0-island_perimeter needs a docstring")
        self.assertTrue(len(valid.__doc__) >= 1,
                        "0-island_perimeter needs a docstring")

    def test_function(self):
        """Test Docstring of function"""
        self.assertIsNot(valid.island_perimeter.__doc__, None,
                         "island_perimeter needs a docstring")
        self.assertTrue(len(valid.island_perimeter.__doc__) >= 1,
                        "island_perimeter needs a docstring")


class TestCases(unittest.TestCase):
    """Test 0-validate_utf8"""

    def test_data(self):
        """Test type of data"""
        func = valid.island_perimeter
        grid = [
            [0, 0, 0, 0, 0, 0],
            [0, 1, 0, 0, 0, 0],
            [0, 1, 0, 0, 0, 0],
            [0, 1, 1, 1, 0, 0],
            [0, 0, 0, 0, 0, 0]
        ]
        self.assertEqual(func(grid), 12)
        grid = [
            [0, 0, 0, 0, 0, 0],
            [0, 1, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0]
        ]
        self.assertEqual(func(grid), 4)
        grid = [
            [0, 0, 0, 0, 0, 0],
            [0, 1, 1, 1, 0, 0],
            [0, 1, 1, 1, 0, 0],
            [0, 1, 1, 1, 0, 0]
        ]
        self.assertEqual(func(grid), 12)
        grid = [
            [0], [0], [0]
        ]
        self.assertEqual(func(grid), 0)
        grid = [
            [1, 1, 1, 1, 1],
            [1, 1, 1, 1, 1],
            [1, 1, 1, 1, 1]
        ]
        self.assertEqual(func(grid), 16)
        grid = [
            [0, 0, 0, 0, 0, 0],
            [0, 1, 1, 0, 0, 0],
            [1, 1, 1, 0, 0, 0],
            [0, 1, 1, 1, 0, 0],
            [0, 0, 0, 1, 1, 1]
        ]
        self.assertEqual(func(grid), 20)
        grid = [
            [0, 1, 0, 0, 0, 1],
            [1, 1, 0, 0, 0, 1],
            [1, 1, 0, 1, 1, 1],
            [0, 1, 1, 1, 0, 0],
            [0, 0, 1, 1, 0, 0]
        ]
        self.assertEqual(func(grid), 28)

    def test_type_error(self):
        """Type test type error"""
        func = valid.island_perimeter
        self.assertEqual(func(2), 0)
        self.assertEqual(func({"2": 3}), 0)
        self.assertEqual(func(2.3), 0)
        self.assertEqual(func('NaN'), 0)
        self.assertEqual(func("Hallo"), 0)
        self.assertEqual(func(True), 0)
        self.assertEqual(func(__name__), 0)
