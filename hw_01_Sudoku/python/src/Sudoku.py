import sys
sys.path.append("..")
try:
    from src.Grid import Grid
except:
    from Grid import Grid

class Sudoku(Grid):
    """
    Extends the Grid class to provide Sudoku-specific functionality.
    """
    def __init__(self, grid_string):
        """
        Initializes the Sudoku with a given grid string.
        
        Params:
            grid_string: A string of 81 digits representing the Sudoku grid.
        """
        super().__init__(grid_string, 9, 3)

    def getInference(self):
        """
        Provides all candidate numbers for each empty cell in the grid.
        
        :return: A 2D list of candidate lists for each cell.
        """
        inferences = [[] for _ in range(self.GRID_SIZE)]
        for row in range(self.GRID_SIZE):
            for col in range(self.GRID_SIZE):
                if self.grid[row][col] == 0:
                    inferences[row].append(self.getCandidates(row, col))
                else:
                    inferences[row].append([self.grid[row][col]])
        return inferences

    def getCandidates(self, row, col):
        """
        Gets all possible candidates for a given empty cell.
        
        :param row: Row index.
        :param col: Column index.
        :return: A list of candidate integers.
        """
        if self.grid[row][col] != 0:
            return [self.grid[row][col]]
        used_numbers = set(self.getRow(row) + self.getColumn(col) + self.getBox(row, col))
        return [n for n in range(1, self.GRID_SIZE + 1) if n not in used_numbers]

    def getSameBox(self, row, col):
        """
        Gets the 3x3 box for the specified cell.
        
        :param row: Row index.
        :param col: Column index.
        :return: A list of integers from the 3x3 box.
        """
        return self.getBox(row, col)
    
    def solve(self):
        """
        Solves the Sudoku puzzle using a backtracking algorithm.
        
        :return: True if solved, False if no solution exists.
        """
        empty = self.findEmpty()
        if not empty:
            return True
        row, col = empty
        for num in self.getCandidates(row, col):
            self.grid[row][col] = num
            if self.solve():
                return True
            self.grid[row][col] = 0
        return False

    def findEmpty(self):
        """
        Finds the first empty cell in the grid.
        
        :return: A tuple (row, col) of the empty cell, or None if full.
        """
        for row in range(self.GRID_SIZE):
            for col in range(self.GRID_SIZE):
                if self.grid[row][col] == 0:
                    return (row, col)
        return None

    def printGrid(self):
        """
        Prints the current state of the grid.
        """
        for row in self.grid:
            print(" ".join(str(num) for num in row))


if __name__ == "__main__":
    # 示例测试用例
    sudoku_string = '017903600000080000900000507072010430000402070064370250701000065000030000005601720'
    sudoku = Sudoku(sudoku_string)
    print(sudoku.check())
    sudoku.printGrid()
    print(sudoku.getInference())
    sudoku.solve()
    sudoku.printGrid()