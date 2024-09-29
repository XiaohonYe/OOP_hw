# Sudoku Solver

This project implements a Sudoku solver using Python. It provides a `Grid` class for basic grid operations and a `Sudoku` class for solving Sudoku puzzles.

## Features

### File Structure

```
|-- src/
|   |-- Grid.py      # Source code the Grid class
|   |-- Sudoku.py  # Source file for the Sudoku class implementation
|   |-- __init__.py    # mark src-directory on disk as Python package directories
|
|-- test/
|   |-- test_Sudoku.py # Test cases
|   |-- __init__.py    # mark src-directory on disk as Python package directories
|
|-- __init__.py    # mark src-directory on disk as Python package directories

```

### Grid Class

- **`__init__(grid_string, GRID_SIZE, BOX_SIZE)`**: Initializes the grid from a string of 81 digits.
- **`parse(grid_string)`**: Converts the input string into a 2D list representing the grid.
- **`checkStr(grid_string)`**: Validates if the input string is suitable for a Sudoku grid.
- **`getRow(row)`**: Returns a specific row from the grid.
- **`getColumn(col)`**: Returns a specific column from the grid.
- **`getBox(row, col)`**: Returns the 3x3 box containing the specified cell.
- **`check()`**: Validates the entire grid according to Sudoku rules.
- **`isValidGroup(group)`**: Checks if a row, column, or box contains unique numbers, excluding zeros.

### Sudoku Class (inherits from Grid)

- **`__init__(grid_string)`**: Initializes the Sudoku with a given grid string.
- **`getInference()`**: Provides all candidate numbers for each empty cell in the grid.
- **`getCandidates(row, col)`**: Returns possible candidates for a given empty cell.
- **`getSameBox(row, col)`**: Retrieves the 3x3 box for the specified cell.
- **`solve()`**: Solves the Sudoku puzzle using a backtracking algorithm.
- **`findEmpty()`**: Finds the first empty cell in the grid.
- **`printGrid()`**: Prints the current state of the grid.

## Usage

### Initialization

Create a `Sudoku` instance with a string of 81 digits:

```python
sudoku_string = '017903600000080000900000507072010430000402070064370250701000065000030000005601720'
sudoku = Sudoku(sudoku_string)
```
### Example

```python
sudoku = Sudoku(sudoku_string)
print("Initial Grid:")
sudoku.printGrid()
print("Each cell's candidate numbers as follows:")
print(sudoku.getInference())

if sudoku.solve():
    print("\nSolved Grid:")
    sudoku.printGrid()
else:
    print("No solution found.")
```

## Requirements

- Python 3.x

## Testing

Run tests using the `unittest` framework:

```bash
python -m unittest discover
```
