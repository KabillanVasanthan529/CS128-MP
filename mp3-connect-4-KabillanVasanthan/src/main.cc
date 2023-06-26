#include <iostream>

#include "board.hpp"
void checkLeftDiag() {
  Board b;
  InitBoard(b);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)4);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)4);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)4);
  DropDiskToBoard(b, DiskType::kPlayer1, (int)4);
  DropDiskToBoard(b, DiskType::kPlayer1, (int)4);
  DropDiskToBoard(b, DiskType::kPlayer1, (int)4);

  DropDiskToBoard(b, DiskType::kPlayer2, (int)3);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)3);
  DropDiskToBoard(b, DiskType::kPlayer1, (int)3);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)3);
  DropDiskToBoard(b, DiskType::kPlayer1, (int)3);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)3);

  DropDiskToBoard(b, DiskType::kPlayer1, (int)2);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)2);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)2);
  DropDiskToBoard(b, DiskType::kPlayer1, (int)2);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)2);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)2);
  
  DropDiskToBoard(b, DiskType::kPlayer1, (int)1);
  DropDiskToBoard(b, DiskType::kPlayer1, (int)1);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)1);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)1);
  DropDiskToBoard(b, DiskType::kPlayer1, (int)1);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)1);
  std::cout << BoardToStr(b) << std::endl;
  std::cout << CheckForWinner(b, DiskType::kPlayer2) << std::endl;

}
void checkVert() {
  Board b;
  InitBoard(b);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)4);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)4);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)4);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)4);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)4);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)4);


  std::cout << BoardToStr(b) << std::endl;
  std::cout << CheckForWinner(b, DiskType::kPlayer1) << std::endl;

}
void checkHor() {
  Board b;
  InitBoard(b);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)1);
  DropDiskToBoard(b, DiskType::kPlayer1, (int)2);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)3);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)4);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)4);
  DropDiskToBoard(b, DiskType::kPlayer1, (int)4);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)4);

  DropDiskToBoard(b, DiskType::kPlayer1, (int)3);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)3);
  DropDiskToBoard(b, DiskType::kPlayer1, (int)2);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)2);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)2);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)5);

  DropDiskToBoard(b, DiskType::kPlayer1, (int)3);
  DropDiskToBoard(b, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(b, DiskType::kPlayer2, (int)5);
  DropDiskToBoard(b, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(b, DiskType::kPlayer1, (int)5);

  std::cout << BoardToStr(b) << std::endl;
  std::cout << SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kRightDiag) << std::endl;

}

int main() {
  checkLeftDiag();
  checkVert();
  checkHor();
}