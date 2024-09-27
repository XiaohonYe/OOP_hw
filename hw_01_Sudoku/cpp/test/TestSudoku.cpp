#include "../src/Sudoku.h"
#include <iostream>
#include <cassert>

void testSudokuSolver() {
    // Test case 1: Solvable Sudoku
    std::string test1 = "017903600000080000900000507072010430000402070064370250701000065000030000005601720";
    Sudoku sudoku1(test1);
    assert(sudoku1.check() && "Test Case 1: Initial grid should be valid");
    bool solved1 = sudoku1.solve();
    assert(solved1 && "Test Case 1: Sudoku should be solvable");

    // Test case 2: Already solved Sudoku
    std::string test2 = "123456789456789123789123456214365897365897214897214365531642978978531642642978531";
    Sudoku sudoku2(test2);
    assert(sudoku2.check() && "Test Case 2: Grid is already solved and valid");
    bool solved2 = sudoku2.solve(); // should detect that it is already solved
    assert(solved2 && "Test Case 2: Already solved Sudoku should remain solved");

    // Test case 3: Invalid Sudoku (duplicate in row)
    std::string test3 = "113456789456789123789123456214365897365897214897214365531642978978531642642978531"; // '1' is repeated in the first row
    Sudoku sudoku3(test3);
    assert(!sudoku3.check() && "Test Case 3: Invalid Sudoku due to duplicate in row");

    
    // Test case 4: Empty Sudoku grid
    std::string test4 = "000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    Sudoku sudoku4(test4);
    assert(sudoku4.check() && "Test Case 4: Empty grid should be valid");
    bool solved4 = sudoku4.solve();
    assert(solved4 && "Test Case 4: Empty grid should be solvable");

    std::cout << "All test cases passed successfully!" << std::endl;
}

int main() {
    testSudokuSolver();
    return 0;
}
