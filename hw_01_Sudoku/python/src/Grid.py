class Grid:
    """
        2D-square list container class for representing an abstract grid.

        Attributes:
            GRID_SIZE (int): The size of the grid (9x9).
            BOX_SIZE (int): The size of each box (3x3).
            grid (list): A 2D list representing the abstract grid.
    """
    def __init__(self, grid_string, GRID_SIZE, BOX_SIZE):
        self.GRID_SIZE = GRID_SIZE
        self.BOX_SIZE = BOX_SIZE
        self.grid = self.parse(grid_string)
    
    def parse(self, grid_string):
        """
        Parse the input string into a 2D-square grid (list of lists).

        Params:
            grid_string (str): A string representing the grid, where each character is a digit.

        Raises:
            ValueError: If the grid string does not have the correct length.
            ValueError: If the grid string contains non-digit characters.
        
        Returns:
            list[list[integers]]: A list of list[integers] parsed for representing the values in the grid.
        """
        if not self.checkStr(grid_string):
            raise ValueError("Invalid input string")
        return [[int(grid_string[i * self.GRID_SIZE + j]) for j in range(self.GRID_SIZE)] for i in range(self.GRID_SIZE)]

    def checkStr(self, grid_string):
        """
        Validate the input string for the Sudoku grid.

        Params:
            grid_string (str): A string representing the Sudoku grid, where each character is a digit.

        Returns:
            False: If the input string does not have the correct length and If the input string contains non-digit characters
            else True.
        """
        return len(grid_string) == self.GRID_SIZE ** 2 and grid_string.isdigit()

    def getRow(self, row):
        """
        Get the values in a specific row of the grid.

        Params:
            row (int): The index of the row to retrieve.

        Returns:
            list: A list of integers representing the values in the specified row.
        """
        return self.grid[row]

    def getColumn(self, col):
        """
        Get the values in a specific column of the grid.

        Params:
            col (int): The index of the column to retrieve.

        Returns:
            list: A list of integers representing the values in the specified column.
        """
        return [self.grid[row][col] for row in range(self.GRID_SIZE)]

    def getBox(self, row, col):
        """
        Get the values in a specific 3x3 box of the grid.

        Params:
            row (int): The row index of a cell within the desired 3x3 box.
            col (int): The column index of a cell within the desired 3x3 box.

        Returns:
            list: A list of integers representing the values in the specified 3x3 box.
        """
        box_row = (row // self.BOX_SIZE) * self.BOX_SIZE
        box_col = (col // self.BOX_SIZE) * self.BOX_SIZE
        return [self.grid[r][c] for r in range(box_row, box_row + self.BOX_SIZE) for c in range(box_col, box_col + self.BOX_SIZE)]

    def check(self):
        """
        Validate the current state of the Sudoku grid is valid according to Sudoku rules.

        Returns:
            True if valid, False otherwise.
        """
        for i in range(self.GRID_SIZE):
            if not self.isValidGroup(self.getRow(i)) or not self.isValidGroup(self.getColumn(i)) or not self.isValidGroup(self.getBox(i, i)):
                return False
        return True

    def isValidGroup(self, group):
        """
        Check if a row, column, or box contains unique numbers excluding zeros.
        
        Params:
            group: A list of integers.
        Returns: 
            True if the group is valid, False otherwise.
        """
        numbers = [num for num in group if num != 0]
        return len(numbers) == len(set(numbers))
