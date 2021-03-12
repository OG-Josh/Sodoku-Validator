  
/*
* Copyright (C) Josh Y. - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited 
* Proprietary and confidential
* Written by Josh Y. <joyang112@gmail.com>, June 2017
*/
//Default Libraries:
//================================
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include "SudokuBoard.h"

SudokuBoard::SudokuBoard() {
  // Initialize value for board
  board = new int*[ROW_MAX];
  for (int i = 0; i < ROW_MAX; i++) {
    board[i] = new int[COL_MAX];
    for (int j = 0; j < COL_MAX; j++) {
      board[i][j] = 0;
    }
  }
}

SudokuBoard::~SudokuBoard() {
  for (int i = 0; i < ROW_MAX; i++) {
    delete[] board[i];
  }
  delete[] board;
}

bool SudokuBoard::LoadBoard(const std::string &filename) {
  bool result = true;
  std::ifstream inputData(filename);
  if (!inputData.is_open()) {
    std::cout << "Can not open the board file: " << filename
              << ". Please check the system!!!!" << std::endl;
    return false;
  } else {
    std::string line;
    int row = 0;
    while (getline(inputData, line)) {
      //std::cout << "DEBUG: line: " << line << std::endl;
      if (row >= ROW_MAX) {
        result = false;
        break;
      }
      // Read line by line
      int col = 0;
      std::stringstream ss(line);
      std::string valueStr;
      while (getline(ss, valueStr, ',')) {
        //std::cout << "\tDEBUG: valueStr: " << valueStr << std::endl;
        if (col >= COL_MAX) {
          result = false;
          break;
        }
        board[row][col++] = atoi(valueStr.c_str());
        // Check this is valid row
        if (col > COL_MAX) {
          std::cout << "Invalid input with line: " << line << std::endl;
          result = false;
          break;
        }
      }

      // Increase row
      row++;
      // Check valid row
      if (row > ROW_MAX) {
        std::cout << "Invalid input data. Please check!!!" << std::endl;
        result = false;
      }
    }
  }

  return result;
}

int SudokuBoard::getValue(int r, int c) {
  if (c < 0 || c > COL_MAX || r < 0 || r > ROW_MAX)
    throw std::out_of_range("Invalid col or row input");
  return board[r][c];
}

void SudokuBoard::PrintBoard() {
  std::ostringstream boardStr;
  boardStr << "------------------------"<< std::endl;
  for (int i = 0; i < 3; i++) {
    boardStr << "| " << board[i][0] << " " << board[i][1] << " " << board[i][2]
             << " | " << board[i][3] << " " << board[i][4] << " " << board[i][5]
             << " |" << board[i][6] << " " << board[i][7] << " " << board[i][8]
             << " |" << std::endl;
  }
  boardStr << "------------------------"<< std::endl;
  for (int i = 3; i < 6; i++) {
    boardStr << "| " << board[i][0] << " " << board[i][1] << " " << board[i][2]
             << " | " << board[i][3] << " " << board[i][4] << " " << board[i][5]
             << " |" << board[i][6] << " " << board[i][7] << " " << board[i][8]
             << " |" << std::endl;
  }
  boardStr << "------------------------"<< std::endl;
  for (int i = 6; i < 9; i++) {
    boardStr << "| " << board[i][0] << " " << board[i][1] << " " << board[i][2]
             << " | " << board[i][3] << " " << board[i][4] << " " << board[i][5]
             << " |" << board[i][6] << " " << board[i][7] << " " << board[i][8]
             << " |" << std::endl;
  }
  boardStr << "------------------------"<< std::endl;
  std::cout << boardStr.str() << std::endl;
//  boardStr << "| " << board[0][0] << " " << board[0][1] << " " << board[0][2] << " | " << board[0][3] << " " << board[0][4] << " " << board[0][5] << " |" << board[0][6] << " " << board[0][7] << " " << board[0][8] << " |" << std::endl;
//  boardStr << "| " << board[1][0] << " " << board[1][1] << " " << board[1][2] << " | " << board[1][3] << " " << board[1][4] << " " << board[1][5] << " |" << board[1][6] << " " << board[1][7] << " " << board[1][8] << " |" << std::endl;
//  boardStr << "| " << board[2][0] << " " << board[2][1] << " " << board[2][2] << " | " << board[2][3] << " " << board[2][4] << " " << board[2][5] << " |" << board[2][6] << " " << board[2][7] << " " << board[2][8] << " |" << std::endl;
//  boardStr << "-------------------------";
}
