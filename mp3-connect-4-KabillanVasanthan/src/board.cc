#include "board.hpp"

// you might need additional includes
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/**************************************************************************/
/* your function definitions                                              */
/**************************************************************************/

void InitBoard(Board& b) {
  // below was minimal to get tests to actually compile and given test case to
  // fail
  for(int i = 0; i < Board::kBoardHeight; i++) {
    for(int j = 0; j < Board::kBoardWidth; j++) {
      b.board[i][j] = DiskType::kEmpty;
    }
  }
}
void DropDiskToBoard(Board& b, DiskType disk, int col) {
  if(col >= Board::kBoardWidth || col < 0) {
    throw std::runtime_error("Invalid Column Number");
  }
  for(int i = 0; i < Board::kBoardHeight; i++) {
    if (b.board[i][col] == DiskType::kEmpty) {
      b.board[i][col] = disk;
      return;
    }
  }
  throw std::runtime_error("All rows in column used");
}


bool CheckHorizontal(Board& b, DiskType disk) {
  for(int i = 0; i < Board::kBoardHeight; i++) {
    int player = 0;
    for (int j = 0; j < Board::kBoardWidth; j++) {
      if(b.board[i][j] == disk) {
        player++;
      } else {
        player = 0;
      }
      if(player >= 4) {
        return true;
      }
    }
  }
  return false;
}
bool CheckVertical(Board& b, DiskType disk) {
  for(int i = 0; i < Board::kBoardWidth; i++) {
    int player = 0;
    for (int j = 0; j < Board::kBoardHeight; j++) {
      if(b.board[j][i] == disk) {
        player++;
      } else {
        player = 0;
      }
      if(player >= 4) {
        return true;
      }
    }
  }
  return false;
}
bool CheckLeftDiagonal(Board& b, DiskType disk) {
  for (int i = 0; i < Board::kBoardHeight; i++) {
    for (int j = 0; j < Board::kBoardWidth; j++) {
      int player = 0;
      for (int k = 0; k < Board::kBoardHeight; k++) {
        if(i+k >= Board::kBoardHeight || j-k < 0) {
          break;
        }
        if(b.board[i+k][j-k] == disk) {
          player++;
        } else {
          player = 0;
        }
        if (player >= 4) {
          return true;
        }
      } 
    }
  }
  return false;
}
bool CheckRightDiagonal(Board& b, DiskType disk) {
  for (int i = 0; i < Board::kBoardHeight; i++) {
    for (int j = 0; j < Board::kBoardWidth; j++) {
      int player = 0;
      for (int k = 0; k < Board::kBoardHeight; k++) {
        if(i+k >= Board::kBoardHeight || j+k >= Board::kBoardWidth) {
          break;
        }
        if(b.board[i+k][j+k] == disk) {
          player++;
        } else {
          player = 0;
        }
        if(player >= 4) {
          std::cout << i << " " << j << " " << k << std::endl;
          return true;
        }
      } 
    }
  }
  return false;
}


bool SearchForWinner(Board& b, DiskType disk, WinningDirection to_check) {
  if(to_check == WinningDirection::kLeftDiag && CheckLeftDiagonal(b,disk)) {
    return true;
  }
  if(to_check == WinningDirection::kVertical && CheckVertical(b,disk)) {
    return true;
  } 
  if(to_check == WinningDirection::kHorizontal && CheckHorizontal(b,disk)) {
    return true;
  }
  if(to_check == WinningDirection::kRightDiag && CheckRightDiagonal(b,disk)) {
    return true;
  }
  return false;
}


bool CheckForWinner(Board& b, DiskType disk) {
  if(SearchForWinner(b, disk, WinningDirection::kHorizontal)) {
    return true;
  }
  if(SearchForWinner(b, disk, WinningDirection::kVertical)) {
    return true;
  }
  if(SearchForWinner(b, disk, WinningDirection::kLeftDiag)) {
    return true;
  }
  if(SearchForWinner(b, disk, WinningDirection::kRightDiag)) {
    return true;
  }
  return false;
}

bool BoardLocationInBounds(int row, int col) {
  return (row < Board::kBoardHeight && col < Board::kBoardWidth && row >= 0 && col >= 0);
}







/**************************************************************************/
/* provided to you                                                        */
/**************************************************************************/
std::string BoardToStr(const Board& b) {
  constexpr int kTotalWidth = Board::kBoardWidth * 11 - Board::kBoardHeight - 1;
  std::stringstream ss;
  ss << std::endl;
  for (int row = Board::kBoardHeight; row > 0; --row) {
    ss << " |";
    for (int col = 0; col < Board::kBoardWidth; ++col) {
      std::string value_here;
      value_here.push_back(static_cast<char>(b.board[row - 1][col]));
      ss << ' ' << CenterStr(value_here, Board::kBoardWidth + 1) << '|';
    }
    ss << std::endl;
    ss << " |" << std::setw(kTotalWidth) << std::setfill('-') << '|'
       << std::endl;
  }
  ss << " |";
  for (int col = 0; col < Board::kBoardWidth; ++col) {
    ss << ' ' << CenterStr(std::to_string(col), Board::kBoardWidth + 1) << '|';
  }
  return ss.str();
}

std::string CenterStr(const std::string& str, int col_width) {
  // quick and easy (but error-prone) implementation
  auto padl = (col_width - str.length()) / 2;
  auto padr = (col_width - str.length()) - padl;
  std::string strf = std::string(padl, ' ') + str + std::string(padr, ' ');
  return strf;
}