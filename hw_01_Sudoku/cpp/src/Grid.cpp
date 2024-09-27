#include "Grid.h"
#include <stdexcept>
#include <set>

Grid::Grid(const std::string& grid_string, int gridSize, int boxSize)
    : GRID_SIZE(gridSize), BOX_SIZE(boxSize) {
    grid = parse(grid_string);
}

std::vector<std::vector<int>> Grid::parse(const std::string& grid_string) {
    if (!checkStr(grid_string)) {
        throw std::invalid_argument("Invalid input string");
    }
    std::vector<std::vector<int>> parsedGrid(GRID_SIZE, std::vector<int>(GRID_SIZE));
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            parsedGrid[i][j] = grid_string[i * GRID_SIZE + j] - '0';
        }
    }
    return parsedGrid;
}

bool Grid::checkStr(const std::string& grid_string) {
    if (grid_string.length() != GRID_SIZE * GRID_SIZE) return false;
    for (char c : grid_string) {
        if (!isdigit(c)) return false;
    }
    return true;
}

std::vector<int> Grid::getRow(int row) {
    return grid[row];
}

std::vector<int> Grid::getColumn(int col) {
    std::vector<int> column(GRID_SIZE);
    for (int row = 0; row < GRID_SIZE; ++row) {
        column[row] = grid[row][col];
    }
    return column;
}

std::vector<int> Grid::getBox(int row, int col) {
    int boxRow = (row / BOX_SIZE) * BOX_SIZE;
    int boxCol = (col / BOX_SIZE) * BOX_SIZE;
    std::vector<int> box;
    for (int r = boxRow; r < boxRow + BOX_SIZE; ++r) {
        for (int c = boxCol; c < boxCol + BOX_SIZE; ++c) {
            box.push_back(grid[r][c]);
        }
    }
    return box;
}

bool Grid::check() {
    for (int i = 0; i < GRID_SIZE; ++i) {
        if (!isValidGroup(getRow(i)) || !isValidGroup(getColumn(i)) || !isValidGroup(getBox(i, i))) {
            return false;
        }
    }
    return true;
}

bool Grid::isValidGroup(const std::vector<int>& group) {
    std::set<int> numbers;
    for (int num : group) {
        if (num != 0) {
            if (numbers.find(num) != numbers.end()) return false;
            numbers.insert(num);
        }
    }
    return true;
}