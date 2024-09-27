#ifndef SUDOKU_H
#define SUDOKU_H

#include "Grid.h"
#include <vector>

/**
 * @class Sudoku
 * @brief Inherits from Grid to add solving functionality using a backtracking algorithm.
 * 
 * The Sudoku class extends the Grid class by implementing methods for solving the grid,
 * generating inferences, and managing candidate values for empty cells.
 */
class Sudoku : public Grid {
public:
    /**
     * @brief Constructor for Sudoku solver.
     * 
     * Initializes the grid and prepares it for solving.
     * 
     * @param grid_string A string representation of the Sudoku grid.
     */
    Sudoku(const std::string& grid_string);

    /**
     * @brief Retrieves inference candidates for each empty cell in the grid.
     * 
     * @return A 3D vector containing candidates for each empty cell.
     */
    std::vector<std::vector<std::vector<int>>> getInference();

    /**
     * @brief Retrieves possible candidate numbers for a specific cell.
     * 
     * @param row The row index of the cell.
     * @param col The column index of the cell.
     * @return A vector of integers representing possible values for the cell.
     */
    std::vector<int> getCandidates(int row, int col);

    /**
     * @brief Retrieves the numbers in the same 3x3 box as the specified cell.
     * 
     * @param row The row index of the cell.
     * @param col The column index of the cell.
     * @return A vector of integers representing the numbers in the same 3x3 box.
     */
    std::vector<int> getSameBox(int row, int col);

    /**
     * @brief Solves the Sudoku grid using a backtracking algorithm.
     * 
     * Attempts to fill the grid recursively and backtracks if an invalid state is reached.
     * 
     * @return true if the grid is solved successfully, false otherwise.
     */
    bool solve();

    /**
     * @brief Finds the first empty cell in the grid.
     * 
     * @return A pair containing the row and column of the first empty cell. 
     *         If no empty cells are found, returns {-1, -1}.
     */
    std::pair<int, int> findEmpty();

    /**
     * @brief Prints the current state of the Sudoku grid to the console.
     */
    void printGrid();
};

#endif // SUDOKU_H
