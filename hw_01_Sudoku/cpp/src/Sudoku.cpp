#include "Sudoku.h"
#include <iostream>
#include <set>

Sudoku::Sudoku(const std::string& grid_string) : Grid(grid_string, 9, 3) {}

std::vector<std::vector<std::vector<int>>> Sudoku::getInference() {
    std::vector<std::vector<std::vector<int>>> inferences(GRID_SIZE, std::vector<std::vector<int>>(GRID_SIZE));
    for (int row = 0; row < GRID_SIZE; ++row) {
        for (int col = 0; col < GRID_SIZE; ++col) {
            if (grid[row][col] == 0) {
                inferences[row][col] = getCandidates(row, col);
            } else {
                inferences[row][col] = {grid[row][col]};
            }
        }
    }
    return inferences;
}

std::vector<int> Sudoku::getCandidates(int row, int col) {
    if (grid[row][col] != 0) {
        return {grid[row][col]};
    }
    std::set<int> used_numbers;
    auto appendToSet = [&used_numbers](const std::vector<int>& numbers) {
        used_numbers.insert(numbers.begin(), numbers.end());
    };
    appendToSet(getRow(row));
    appendToSet(getColumn(col));
    appendToSet(getBox(row, col));

    std::vector<int> candidates;
    for (int n = 1; n <= GRID_SIZE; ++n) {
        if (used_numbers.find(n) == used_numbers.end()) {
            candidates.push_back(n);
        }
    }
    return candidates;
}

std::vector<int> Sudoku::getSameBox(int row, int col) {
    return getBox(row, col);
}

bool Sudoku::solve() {
    auto empty = findEmpty();
    if (empty.first == -1) {
        return true;  // No empty cells, puzzle is solved
    }
    int row = empty.first;
    int col = empty.second;
    for (int num : getCandidates(row, col)) {
        grid[row][col] = num;
        if (solve()) {
            return true;  // Solved successfully
        }
        grid[row][col] = 0;  // Backtrack
    }
    return false;  // Trigger backtracking
}

std::pair<int, int> Sudoku::findEmpty() {
    for (int row = 0; row < GRID_SIZE; ++row) {
        for (int col = 0; col < GRID_SIZE; ++col) {
            if (grid[row][col] == 0) {
                return {row, col};
            }
        }
    }
    return {-1, -1};  // No empty cells found
}

void Sudoku::printGrid() {
    for (const auto& row : grid) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}
