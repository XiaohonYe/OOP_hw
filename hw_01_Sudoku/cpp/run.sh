g++ src/main.cpp src/Grid.cpp src/Sudoku.cpp -o sudoku_solver
./sudoku_solver
rm -rf ./sudoku_solver.exe

g++ test/TestSudoku.cpp src/Grid.cpp src/Sudoku.cpp -o sudoku_test
./sudoku_test
rm -rf ./sudoku_test.exe

