/*
* Copyright (C) Josh Y. - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited 
* Proprietary and confidential
* Written by Josh Y. <joyang112@gmail.com>, June 2017
*/
//Default Libraries:
//================================
#include <iostream>
#include <stdexcept>
#include "SudokuSolver.h"

SudokuSolver::SudokuSolver() {
  board = nullptr;
}

SudokuSolver::SudokuSolver(SudokuBoard *b)
    :
    board(b) {
}

SudokuSolver::SudokuSolver(const std::string &solverfile) {
  board = new SudokuBoard();
  if (!board->LoadBoard(solverfile))
    throw std::runtime_error("Can not loading solver file");
}

SudokuSolver::~SudokuSolver() {
  if (board != nullptr)
    delete board;
}
bool SudokuSolver::isValidRowAndCol() const {
  // Check row first
  for (int c = 0; c < COL_MAX; c++) {
    // The index will be the number and the value is counter the number of existing number
    int digitalNumberCnt[10] = { 0 };
    for (int r = 0; r < ROW_MAX; r++) {
      int currentValue = board->getValue(c, r);
      if (digitalNumberCnt[currentValue] == 0) {
        //If this is not appear before. Mark this value is exist
        digitalNumberCnt[currentValue] = 1;
      } else {
        // If this is appear before. This is error row
        std::cout << "COL " << c + 1 << " is invalid. The number " << currentValue
                  << " appear more than 1 time" << std::endl;
        return false;
      }
    }
  }

  // Check the column
  for (int r = 0; r < ROW_MAX; r++) {
    // The index will be the number and the value is counter the number of existing number
    int digitalNumberCnt[10] = { 0 };
    for (int c = 0; c < COL_MAX; c++) {
      int currentValue = board->getValue(r, c);
      if (digitalNumberCnt[currentValue] == 0) {
        //If this is not appear before. Mark this value is exist
        digitalNumberCnt[currentValue] = 1;
      } else {
        // If this is appear before. This is error row
        std::cout << "ROW " << r + 1 << " is invalid. The number " << currentValue
                  << " appear more than 1 time" << std::endl;
        return false;
      }
    }
  }
  return true;
}

// Check is valid sub grid
bool SudokuSolver::isValidSubGrid(const int &rowsStart,
                                  const int &colStart) const {
//  std::cout << "DEBUG: isValidSubGrid: " << rowsStart << " : " << colStart
//            << std::endl;
  // Check valid rows start and cols start
  if (rowsStart % 3 != 0 || rowsStart < 0 || rowsStart > ROW_MAX - 3
      || colStart % 3 != 0 || colStart < 0 || colStart > COL_MAX - 3) {
    throw std::out_of_range(
        "Invalid rows start and col start in the check function.");
  }
  int digitalNumberCnt[10] = { 0 };
  for (int r = rowsStart; r < rowsStart + 3; r++) {
    for (int c = colStart; c < colStart + 3; c++) {
      int currentValue = board->getValue(r, c);
      if (digitalNumberCnt[currentValue] == 0) {
        //If this is not appear before. Mark this value is exist
        digitalNumberCnt[currentValue] = 1;
      } else {
        // If this is appear before. This is error row
        std::cout << "The SUB GRID with start rows: " << rowsStart
                  << " and start cols: " << colStart << " is invalid. The number " << currentValue << " apper more than 1 times"
                  << std::endl;
//        std::cout << "DEBUG: isValidSubGrid: " << rowsStart << " : " << colStart
//                  << ".Return: " << true << std::endl;
        return false;
      }
    }
  }
//  std::cout << "DEBUG: isValidSubGrid: " << rowsStart << " : " << colStart
//            << "Return: " << true << std::endl;
  return true;
}
