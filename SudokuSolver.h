  /*
* Copyright (C) Josh Y. - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited 
* Proprietary and confidential
* Written by Josh Y. <joyang112@gmail.com>, June 2017
*/
//Default Libraries:
//================================
#include "SudokuBoard.h"

class SudokuSolver {
 public:
  SudokuSolver();
  SudokuSolver(SudokuBoard* b);
  SudokuSolver(const std::string& solverfile);
  ~SudokuSolver();
  bool isValidRowAndCol() const;
  bool isValidSubGrid(const int& rowsStart, const int&colStart) const;
  void PrintBoard() {
    board->PrintBoard();
  }
 private:
  SudokuBoard *board;
};



