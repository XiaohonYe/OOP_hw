#ifndef GRID_H
#define GRID_H

#include <vector>
#include <string>

/**
 * @class Grid
 * @brief Represents a general Sudoku grid, handling basic operations like validation and parsing.
 *
 * The Grid class is responsible for storing the state of the Sudoku grid, providing utility 
 * functions for retrieving rows, columns, and 3x3 boxes, and checking the grid for validity.
 */
class Grid {
public:
    /**
     * @brief Constructor for initializing the grid.
     * 
     * @param grid_string A string representation of the Sudoku grid.
     * @param gridSize The size of the grid (typically 9 for standard Sudoku).
     * @param boxSize The size of each 3x3 box (typically 3 for standard Sudoku).
     */
    Grid(const std::string& grid_string, int gridSize, int boxSize);

    /**
     * @brief Retrieves a specific row from the grid.
     * 
     * @param row The index of the row to retrieve.
     * @return A vector containing the values in the specified row.
     */
    std::vector<int> getRow(int row);

    /**
     * @brief Retrieves a specific column from the grid.
     * 
     * @param col The index of the column to retrieve.
     * @return A vector containing the values in the specified column.
     */
    std::vector<int> getColumn(int col);

    /**
     * @brief Retrieves a specific 3x3 box from the grid.
     * 
     * @param row The row index to identify the box.
     * @param col The column index to identify the box.
     * @return A vector containing the values in the corresponding 3x3 box.
     */
    std::vector<int> getBox(int row, int col);

    /**
     * @brief Checks if the current grid configuration is valid.
     * 
     * This function validates that the grid has no duplicate numbers in any row, column, or 3x3 box.
     * 
     * @return true if the grid is valid, false otherwise.
     */
    bool check();

protected:
    int GRID_SIZE; ///< The size of the grid (e.g., 9 for standard Sudoku).
    int BOX_SIZE;  ///< The size of each box (e.g., 3 for 3x3 boxes in standard Sudoku).
    std::vector<std::vector<int>> grid; ///< 2D vector representing the Sudoku grid.

    /**
     * @brief Parses the input grid string and populates the grid.
     * 
     * @param grid_string The string representation of the grid.
     * @return A 2D vector representing the parsed grid.
     */
    std::vector<std::vector<int>> parse(const std::string& grid_string);

    /**
     * @brief Validates the input grid string format.
     * 
     * Checks that the input string has the correct length and contains only digits.
     * 
     * @param grid_string The input grid string.
     * @return true if the string is valid, false otherwise.
     */
    bool checkStr(const std::string& grid_string);

    /**
     * @brief Checks if a group (row, column, or box) contains only unique numbers.
     * 
     * @param group A vector representing a row, column, or 3x3 box.
     * @return true if the group is valid, false otherwise.
     */
    bool isValidGroup(const std::vector<int>& group);
};

#endif // GRID_H
