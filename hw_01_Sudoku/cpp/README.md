# Sudoku Solver in C++

## Project Structure

This project implements a simple Sudoku solver using C++. The implementation is structured into separate header and source files for clarity, modularity, and ease of maintenance. Below is a detailed description of the code organization and functionality:

### File Structure

```
|-- src/
|   |-- Grid.h      # Header for the Grid class
|   |-- Grid.cpp    # Source file for the Grid class implementation
|   |-- Sudoku.h    # Header for the Sudoku class (inherits from Grid)
|   |-- Sudoku.cpp  # Source file for the Sudoku class implementation
|   |-- main.cpp    # Entry point demonstrating Sudoku solving
|
|-- test/
|   |-- TestSudoku.cpp # Test cases
|
|-- run.sh (optional)

```

### **Grid.h**

The `Grid` class defines a basic representation of a Sudoku grid. It provides utility methods for extracting rows, columns, and boxes, as well as for checking the validity of the grid.

**Methods:**
- **Constructor**: Takes a grid string, grid size, and box size.
- `getRow(int row)`: Returns the elements of the specified row.
- `getColumn(int col)`: Returns the elements of the specified column.
- `getBox(int row, int col)`: Returns the elements in the box (sub-grid) associated with the given cell.
- `check()`: Validates whether the grid is correctly initialized and adheres to Sudoku rules.
- `parse()`: Parses a string representation of the grid into a 2D vector.
- `checkStr()`: Checks the validity of the input string.
- `isValidGroup()`: Verifies if a group of numbers (row, column, or box) contains valid entries.

### **Grid.cpp**

This file implements the methods defined in `Grid.h`. It handles the grid's initialization from a string, validates the input, and provides utility functions to retrieve specific parts of the grid (rows, columns, boxes) and check the validity of the grid configuration.

### **Sudoku.h**

The `Sudoku` class extends `Grid` by adding functionalities to solve the puzzle. This class includes methods to infer possible candidates for empty cells, solve the grid using backtracking, and print the grid state.

**Additional Methods:**
- `getInference()`: Returns possible candidates for each cell.
- `getCandidates(int row, int col)`: Returns valid numbers that can be placed in the specified cell.
- `solve()`: Attempts to solve the Sudoku puzzle using backtracking.
- `findEmpty()`: Finds the next empty cell in the grid.
- `printGrid()`: Prints the current state of the grid to the console.

### **Sudoku.cpp**

This file implements the solving logic defined in `Sudoku.h`. The backtracking algorithm is used to fill the grid recursively until a valid solution is found.

- The `solve()` method attempts to fill empty cells with valid candidates. If an invalid state is reached, it backtracks and tries another candidate.
- The `getCandidates()` method generates valid numbers that can be placed in a specific cell by checking the corresponding row, column, and box.

### **main.cpp**

This file contains the `main()` function, which demonstrates the functionality of the `Sudoku` class. It initializes a Sudoku puzzle from a string, checks its initial validity, solves it, and prints the final solution (if found).

**Steps in `main()`**:
1. A Sudoku puzzle is initialized using a string representation.
2. The `check()` method verifies if the initial grid is valid.
3. The `solve()` method attempts to solve the puzzle.
4. The final grid (solved or unsolved) is printed.

### Example Execution

For the input puzzle:

```
017903600000080000900000507072010430000402070064370250701000065000030000005601720

equals:

017903600
000080000
900000507
072010430
000402070
064370250
701000065
000030000
005601720
```

The program will validate and attempt to solve the puzzle, printing the solution if successful.

### Compilation and Execution

To compile and run the code, use the following commands:

```bash
g++ main.cpp Grid.cpp Sudoku.cpp -o sudoku_solver
./sudoku_solver

g++ test/TestSudoku.cpp src/Grid.cpp src/Sudoku.cpp -o sudoku_test
./sudoku_test
```
or you can find the commands in run.sh.

### Key Concepts and Design

- **Modularity**: By separating the grid logic (`Grid`) from the solving logic (`Sudoku`), the code is easier to maintain and extend.
- **Object-Oriented Design**: The `Sudoku` class inherits from `Grid`, reusing grid manipulation methods while extending functionality with solving logic.
