#include "Sudoku.h"
#include <iostream>

int main() {
    std::string sudoku_string = "017903600000080000900000507072010430000402070064370250701000065000030000005601720";
    Sudoku sudoku(sudoku_string);
    std::cout << "Initial validity: " << std::boolalpha << sudoku.check() << std::endl;
    sudoku.printGrid();
    
    if (sudoku.solve()) {
        std::cout << "\nSolved Sudoku:" << std::endl;
        sudoku.printGrid();
    } else {
        std::cout << "No solution found." << std::endl;
    }

    return 0;
}