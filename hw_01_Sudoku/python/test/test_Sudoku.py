import unittest
import sys
sys.path.append('..')
sys.path.append('.')
from src.Sudoku import Sudoku

class TestSudoku(unittest.TestCase):
    def setUp(self):
        self.sudoku_string = '017903600000080000900000507072010430000402070064370250701000065000030000005601720'
        self.sudoku = Sudoku(self.sudoku_string)

    def test_parse(self):
        self.assertEqual(len(self.sudoku.grid), 9)
        self.assertEqual(len(self.sudoku.grid[0]), 9)

    def test_check_valid(self):
        self.assertTrue(self.sudoku.check())

    def test_get_row(self):
        row = self.sudoku.getRow(0)
        self.assertEqual(len(row), 9)
        self.assertEqual(row[1], 1)

    def test_get_column(self):
        column = self.sudoku.getColumn(0)
        self.assertEqual(len(column), 9)
        self.assertEqual(column[2], 9)

    def test_get_box(self):
        box = self.sudoku.getBox(0, 0)
        self.assertEqual(len(box), 9)
        self.assertIn(9, box)

    def test_get_candidates(self):
        candidates = self.sudoku.getCandidates(0, 1)
        self.assertIn(1, candidates)

    def test_solve(self):
        solved = self.sudoku.solve()
        self.assertTrue(solved)
        self.assertTrue(self.sudoku.check())

if __name__ == '__main__':
    unittest.main()