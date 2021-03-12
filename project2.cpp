  
/*
* Copyright (C) Josh Y. - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited 
* Proprietary and confidential
* Written by Josh Y. <joyang112@gmail.com>, June 2017
*/
//Default Libraries:
//================================
#include <iostream>
#include <functional>
#include <vector>
#include <thread>
#include "SudokuSolver.h"

#define MAX_SUB_GRID 9

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Used: " << argv[0] << " <solverfile.txt>" << std::endl;
    return 1;
  }
  SudokuSolver *solver = new SudokuSolver(argv[1]);
  solver->PrintBoard();
  std::cout << std::endl;
  bool isValidColRow = false;
  bool isValidSubGrid[MAX_SUB_GRID] = { false };
  int startRowList[MAX_SUB_GRID] = { 0, 0, 0, 3, 3, 3, 6, 6, 6 };
  int startColList[MAX_SUB_GRID] = { 0, 3, 6, 0, 3, 6, 0, 3, 6 };
  // Create a vector of threads
  std::vector<std::thread> checkSubGridList;
  // Create thread to check all subgrid
  for (int i = 0; i < MAX_SUB_GRID; i++) {
    std::thread checkSubGrid(
        [&](int _i) {
          int ind = _i;
          *(isValidSubGrid + ind) = solver->isValidSubGrid(startRowList[ind],
                                                     startColList[ind]);
        }, i);
    checkSubGridList.push_back(std::move(checkSubGrid));
  }
  // Check all col row
  std::thread checkRowColThread([&]() {
    isValidColRow = solver->isValidRowAndCol();
  });

  // Join all thread
  for (size_t i = 0; i < checkSubGridList.size(); i++) {
    checkSubGridList[i].join();
  }
  // Join
  checkRowColThread.join();
  // Check all condition is correct
  bool isSolverBoard = true;
  for (int i = 0; i < MAX_SUB_GRID; i++) {
    //std::cout << "DEBUG: isValidSubGrid[" << i << "]: " << isValidSubGrid[i] << std::endl;
    isSolverBoard &= isValidSubGrid[i];
  }
  //std::cout << "DEBUG: isValidColRow: " << isValidColRow << std::endl;
  isSolverBoard &= isValidColRow;
  if (isSolverBoard) {
    std::cout << "The board is solved!!!!" << std::endl;
  } else {
    std::cout << "The board is NOT solved!!!!" << std::endl;
  }
  delete solver;
  return 0;
}

