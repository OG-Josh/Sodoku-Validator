  
/*
* Copyright (C) Josh Y. - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited 
* Proprietary and confidential
* Written by Josh Y. <joyang112@gmail.com>, June 2017
*/
//Default Libraries:
//================================
#ifndef SUDOKUBOARD_H_
#define SUDOKUBOARD_H_

// Board 9 x 9
#define ROW_MAX 9
#define COL_MAX 9

#include <string>
class SudokuBoard {
 public:
  SudokuBoard();
  ~SudokuBoard();
  bool LoadBoard(const std::string &filename);
  int getValue(int c, int l);
  void PrintBoard();
 private:
  int **board;

};

#endif /* SUDOKUBOARD_H_ */
