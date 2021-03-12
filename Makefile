all: clean pro2
clean:
	rm -f pro2 core*
pro2:
	g++ -g -Wall -std=c++11 -pthread -W -Wall project2.cpp SudokuBoard.cpp SudokuSolver.cpp -o pro2
