// clang-format off
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//  Written By : Michael R. Nowak                Environment : ubuntu:latest               //
//  Date ......: 2022/02/07                      Compiler ...: clang-10                    //
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
// clang-format on
/////////////////////////////////////////////////////////////////////////////////////////////
//                             Framework Set-up //
/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif
#include "catch.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                                 Includes //
/////////////////////////////////////////////////////////////////////////////////////////////
#include <stdexcept>

#include "board.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                             Helpers/Constants //
/////////////////////////////////////////////////////////////////////////////////////////////
constexpr int kBoardWidth = 7;
constexpr int kBoardHeight = 6;

bool AreEqual(DiskType solution[][kBoardWidth],
              DiskType student[][kBoardWidth]) {
  for (int i = 0; i < kBoardHeight; ++i) {
    for (int j = 0; j < kBoardWidth; ++j) {
      if (solution[i][j] != student[i][j]) return false;
    }
  }
  return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////
//                                Test Cases //
/////////////////////////////////////////////////////////////////////////////////////////////

TEST_CASE("Board initialization", "[board_init]") {
  // SECTION("Can use sections") {}
  // clang-format off
  DiskType solution[kBoardHeight][kBoardWidth] = { 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty} 
  };
  // clang-format on
  Board student;  // NOLINT
  InitBoard(student);
  REQUIRE(AreEqual(solution, student.board));
}
TEST_CASE("Empty Board", "[board_init]") {
  // SECTION("Can use sections") {}
  // clang-format off
  DiskType solution[kBoardHeight][kBoardWidth] = { 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty} 
  };
  // clang-format on
  Board student;  // NOLINT
  InitBoard(student);
  REQUIRE(AreEqual(solution, student.board));
  REQUIRE(CheckForWinner(student, DiskType::kPlayer1) == false);
  REQUIRE(CheckForWinner(student, DiskType::kPlayer2) == false);
  REQUIRE(BoardLocationInBounds(0,0));
}


TEST_CASE("Adding Disk", "Fall to Bottom") {
  DiskType solution[kBoardHeight][kBoardWidth] = { 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer1, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty} 
  };
  Board student;
  InitBoard(student);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  REQUIRE(AreEqual(solution, student.board));
}
TEST_CASE("Full Column", "Full Column") {
  DiskType solution[kBoardHeight][kBoardWidth] = { 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer1, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer1, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer1, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer1, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer1, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer1, DiskType::kEmpty} 
  };
  Board student;
  InitBoard(student);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  REQUIRE(AreEqual(solution, student.board));
}
TEST_CASE("Full Board", "Full Column") {
  DiskType solution[kBoardHeight][kBoardWidth] = { 
    {DiskType::kPlayer1, DiskType::kPlayer1, DiskType::kPlayer1, DiskType::kPlayer1, DiskType::kPlayer1, DiskType::kPlayer1, DiskType::kPlayer1}, 
    {DiskType::kPlayer1, DiskType::kPlayer1, DiskType::kPlayer1, DiskType::kPlayer1, DiskType::kPlayer1, DiskType::kPlayer1, DiskType::kPlayer1}, 
    {DiskType::kPlayer2, DiskType::kPlayer2, DiskType::kPlayer2, DiskType::kPlayer2, DiskType::kPlayer2, DiskType::kPlayer2, DiskType::kPlayer2}, 
    {DiskType::kPlayer1, DiskType::kPlayer1, DiskType::kPlayer1, DiskType::kPlayer1, DiskType::kPlayer1, DiskType::kPlayer1, DiskType::kPlayer1}, 
    {DiskType::kPlayer2, DiskType::kPlayer2, DiskType::kPlayer2, DiskType::kPlayer2, DiskType::kPlayer2, DiskType::kPlayer2, DiskType::kPlayer2}, 
    {DiskType::kPlayer1, DiskType::kPlayer1, DiskType::kPlayer1, DiskType::kPlayer1, DiskType::kPlayer1, DiskType::kPlayer1, DiskType::kPlayer1} 
  };
  Board student;
  InitBoard(student);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)0);

  DropDiskToBoard(student, DiskType::kPlayer1, (int)1);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)1);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)1);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)1);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)1);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)1);

  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);

  DropDiskToBoard(student, DiskType::kPlayer1, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)3);

  DropDiskToBoard(student, DiskType::kPlayer1, (int)4);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)4);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)4);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)4);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)4);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)4);

  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);

  DropDiskToBoard(student, DiskType::kPlayer1, (int)6);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)6);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)6);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)6);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)6);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)6);

  REQUIRE(AreEqual(solution, student.board));
}

TEST_CASE("Multiple players", "Full Column") {
  DiskType solution[kBoardHeight][kBoardWidth] = { 
    {DiskType::kPlayer2, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer1, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer1, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer2, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer1, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer2, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer1, DiskType::kEmpty} 
  };
  Board student;
  InitBoard(student);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)0);

  REQUIRE(AreEqual(solution, student.board));
}
TEST_CASE("Extra Disk", "Full Column + Extra") {
  Board student;
  InitBoard(student);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  REQUIRE_THROWS_AS(DropDiskToBoard(student, DiskType::kPlayer1, 5), std::runtime_error);

}
TEST_CASE("Invalid Column", "Hey") {
  Board student;
  InitBoard(student);
  REQUIRE_THROWS_AS(DropDiskToBoard(student, DiskType::kPlayer1, 7), std::runtime_error);

}
TEST_CASE("Invalid Column Under", "Hey") {
  Board student;
  InitBoard(student);
  REQUIRE_THROWS_AS(DropDiskToBoard(student, DiskType::kPlayer1, -1), std::runtime_error);

}
TEST_CASE("VerticalWin", "Full Column") {
  Board student;
  InitBoard(student);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  REQUIRE(SearchForWinner(student, DiskType::kPlayer1, WinningDirection::kVertical) == true);
}
TEST_CASE("HorizontalWin", "Full Column") {
  DiskType solution[kBoardHeight][kBoardWidth] = { 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer1, DiskType::kPlayer1, DiskType::kPlayer1, DiskType::kPlayer1, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty} 
  };
  Board student;
  InitBoard(student);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)4);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  REQUIRE(AreEqual(solution, student.board));
  REQUIRE(SearchForWinner(student, DiskType::kPlayer1, WinningDirection::kHorizontal) == true);
  REQUIRE(CheckForWinner(student, DiskType::kPlayer1) == true);
  REQUIRE(SearchForWinner(student, DiskType::kPlayer1, WinningDirection::kLeftDiag) == false);
}
TEST_CASE("LeftDiagonalWin", "Full Column") {
  Board student;
  InitBoard(student);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)0);

  DropDiskToBoard(student, DiskType::kPlayer2, (int)1);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)1);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)1);

  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);
  
  DropDiskToBoard(student, DiskType::kPlayer1, (int)3);

  REQUIRE(SearchForWinner(student, DiskType::kPlayer1, WinningDirection::kLeftDiag) == true);
  REQUIRE(CheckForWinner(student, DiskType::kPlayer1) == true);
}
TEST_CASE("TopHorizontal", "Full Column") {
  Board student;
  InitBoard(student);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)0);

  DropDiskToBoard(student, DiskType::kPlayer1, (int)1);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)1);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)1);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)1);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)1);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)1);
  
  DropDiskToBoard(student, DiskType::kPlayer2, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);
  
  DropDiskToBoard(student, DiskType::kPlayer1, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)3);

  REQUIRE(SearchForWinner(student, DiskType::kPlayer1, WinningDirection::kHorizontal) == true);
  REQUIRE(CheckForWinner(student, DiskType::kPlayer1) == true);
}
TEST_CASE("RightDiagonalWin", "Full Column") {
  Board student;
  InitBoard(student);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)3);

  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);

  DropDiskToBoard(student, DiskType::kPlayer2, (int)1);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)1);
  
  DropDiskToBoard(student, DiskType::kPlayer1, (int)0);
  std::cout << BoardToStr(student) << std::endl;
  REQUIRE(SearchForWinner(student, DiskType::kPlayer1, WinningDirection::kRightDiag) == true);
  REQUIRE(SearchForWinner(student, DiskType::kPlayer2, WinningDirection::kRightDiag) == false);
}
TEST_CASE("InBoundsMethod", "Full Column") {
  REQUIRE(BoardLocationInBounds(8, 10) == false);
  REQUIRE(BoardLocationInBounds(5, 5) == true);
  REQUIRE(BoardLocationInBounds(5, -1) == false);
  REQUIRE(BoardLocationInBounds(-1, 2) == false);
  REQUIRE(BoardLocationInBounds(10, 2) == false);
}
TEST_CASE("EdgeCaseVertical", "Full Column") {
  Board student;
  InitBoard(student);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)0);

  DropDiskToBoard(student, DiskType::kPlayer2, (int)6);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)6);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)6);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)6);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)6);


  std::cout << BoardToStr(student) << std::endl;
  REQUIRE(SearchForWinner(student, DiskType::kPlayer1, WinningDirection::kVertical) == true);
  REQUIRE(CheckForWinner(student, DiskType::kPlayer1) == true);
  REQUIRE(SearchForWinner(student, DiskType::kPlayer2, WinningDirection::kVertical) == true);
  REQUIRE(CheckForWinner(student, DiskType::kPlayer2) == true);
}
TEST_CASE("TopRowHorizontal", "Full Column") {
  Board student;
  InitBoard(student);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)0);

  DropDiskToBoard(student, DiskType::kPlayer1, (int)1);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)1);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)1);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)1);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)1);

  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)2);
  
  DropDiskToBoard(student, DiskType::kPlayer1, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)3);


  std::cout << BoardToStr(student) << std::endl;
  REQUIRE(SearchForWinner(student, DiskType::kPlayer1, WinningDirection::kVertical) == true);
  REQUIRE(SearchForWinner(student, DiskType::kPlayer2, WinningDirection::kHorizontal) == true);
  REQUIRE(CheckForWinner(student, DiskType::kPlayer1) == true);
  REQUIRE(CheckForWinner(student, DiskType::kPlayer2) == true);
}
TEST_CASE("Not horizontal", "Full Column") {
  Board student;
  InitBoard(student);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)1);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);
  
  DropDiskToBoard(student, DiskType::kPlayer2, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)2);
  
  DropDiskToBoard(student, DiskType::kPlayer1, (int)1);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)2);

  


  REQUIRE(SearchForWinner(student, DiskType::kPlayer2, WinningDirection::kVertical) == false);
  REQUIRE(CheckForWinner(student, DiskType::kPlayer2) == false);
  REQUIRE(SearchForWinner(student, DiskType::kPlayer1, WinningDirection::kHorizontal) == false);
  REQUIRE(SearchForWinner(student, DiskType::kPlayer1, WinningDirection::kRightDiag) == false);
  REQUIRE(CheckForWinner(student, DiskType::kPlayer1) == false);
}
TEST_CASE("Multiple Wins", "Full Column") {
  Board student;
  InitBoard(student);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)1);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)3);
  
  DropDiskToBoard(student, DiskType::kPlayer1, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)3);
  

  REQUIRE(SearchForWinner(student, DiskType::kPlayer1, WinningDirection::kVertical) == true);
  REQUIRE(SearchForWinner(student, DiskType::kPlayer1, WinningDirection::kHorizontal) == true);
  REQUIRE(CheckForWinner(student, DiskType::kPlayer1) == true);
} 
TEST_CASE("HorizontalWinPlayer2", "Full Column") {
  DiskType solution[kBoardHeight][kBoardWidth] = { 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer2, DiskType::kPlayer2, DiskType::kPlayer2, DiskType::kPlayer2, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty} 
  };
  Board student;
  InitBoard(student);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)4);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)5);
  REQUIRE(AreEqual(solution, student.board));
  REQUIRE(SearchForWinner(student, DiskType::kPlayer2, WinningDirection::kHorizontal) == true);
  REQUIRE(CheckForWinner(student, DiskType::kPlayer2) == true);
  REQUIRE(SearchForWinner(student, DiskType::kPlayer1, WinningDirection::kLeftDiag) == false);
}
TEST_CASE("Right Diagonal Player2", "Full Column") {
  DiskType solution[kBoardHeight][kBoardWidth] = { 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer2, DiskType::kPlayer1, DiskType::kPlayer2, DiskType::kPlayer1, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer2, DiskType::kPlayer2, DiskType::kPlayer1, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer2, DiskType::kPlayer2, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer2, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty} 
  };
  Board student;
  InitBoard(student);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)4);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  
  DropDiskToBoard(student, DiskType::kPlayer2, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)4);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);

  DropDiskToBoard(student, DiskType::kPlayer2, (int)4);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)5);

  REQUIRE(AreEqual(solution, student.board));
  REQUIRE(SearchForWinner(student, DiskType::kPlayer2, WinningDirection::kRightDiag) == true);
  REQUIRE(CheckForWinner(student, DiskType::kPlayer2) == true);
  REQUIRE(SearchForWinner(student, DiskType::kPlayer1, WinningDirection::kHorizontal) == false);
}
TEST_CASE("Left Diagonal Player2", "Full Column") {
  DiskType solution[kBoardHeight][kBoardWidth] = { 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer2, DiskType::kPlayer1, DiskType::kPlayer1, DiskType::kPlayer2, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer2, DiskType::kPlayer1, DiskType::kPlayer2, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer1, DiskType::kPlayer2, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer2, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty} 
  };
  Board student;
  InitBoard(student);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)2);
  
  DropDiskToBoard(student, DiskType::kPlayer1, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)3);

  DropDiskToBoard(student, DiskType::kPlayer1, (int)4);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)4);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)5);

  REQUIRE(AreEqual(solution, student.board));
  REQUIRE(SearchForWinner(student, DiskType::kPlayer2, WinningDirection::kLeftDiag) == true);
  REQUIRE(CheckForWinner(student, DiskType::kPlayer2) == true);
  REQUIRE(CheckForWinner(student, DiskType::kPlayer1) == false);
  REQUIRE(SearchForWinner(student, DiskType::kPlayer1, WinningDirection::kVertical) == false);
}
TEST_CASE("Vertical Player 2", "Full Column") {
  DiskType solution[kBoardHeight][kBoardWidth] = { 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer2, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer2, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer2, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer2, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty} 
  };
  Board student;
  InitBoard(student);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)2);

  REQUIRE(AreEqual(solution, student.board));
  REQUIRE(SearchForWinner(student, DiskType::kPlayer2, WinningDirection::kVertical) == true);
  REQUIRE(CheckForWinner(student, DiskType::kPlayer2) == true);
  REQUIRE(SearchForWinner(student, DiskType::kPlayer1, WinningDirection::kRightDiag) == false);
}
TEST_CASE("No win", "Full Column") {
  DiskType solution[kBoardHeight][kBoardWidth] = { 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer2, DiskType::kPlayer1, DiskType::kPlayer1, DiskType::kPlayer2, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer1, DiskType::kPlayer2, DiskType::kPlayer2, DiskType::kPlayer1, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer2, DiskType::kPlayer1, DiskType::kPlayer1, DiskType::kPlayer2, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer1, DiskType::kPlayer2, DiskType::kPlayer2, DiskType::kPlayer1, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty} 
  };
  Board student;
  InitBoard(student);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);

  DropDiskToBoard(student, DiskType::kPlayer1, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)3);

  DropDiskToBoard(student, DiskType::kPlayer1, (int)4);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)4);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)4);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)4);

  DropDiskToBoard(student, DiskType::kPlayer2, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);

  REQUIRE(AreEqual(solution, student.board));
  REQUIRE(SearchForWinner(student, DiskType::kPlayer2, WinningDirection::kVertical) == false);
  REQUIRE(CheckForWinner(student, DiskType::kPlayer2) == false);
  REQUIRE(CheckForWinner(student, DiskType::kPlayer1) == false);
  REQUIRE(SearchForWinner(student, DiskType::kPlayer2, WinningDirection::kRightDiag) == false);
  REQUIRE(SearchForWinner(student, DiskType::kPlayer2, WinningDirection::kHorizontal) == false);
  REQUIRE(SearchForWinner(student, DiskType::kPlayer2, WinningDirection::kLeftDiag) == false);
  REQUIRE(SearchForWinner(student, DiskType::kPlayer1, WinningDirection::kRightDiag) == false);
  REQUIRE(SearchForWinner(student, DiskType::kPlayer1, WinningDirection::kHorizontal) == false);
  REQUIRE(SearchForWinner(student, DiskType::kPlayer1, WinningDirection::kLeftDiag) == false);
  REQUIRE(SearchForWinner(student, DiskType::kPlayer1, WinningDirection::kVertical) == false);

}
TEST_CASE("Left Diagonal Edge", "Full Column") {
  DiskType solution[kBoardHeight][kBoardWidth] = { 
    {DiskType::kPlayer2, DiskType::kPlayer1, DiskType::kPlayer1, DiskType::kPlayer2, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kPlayer2, DiskType::kPlayer1, DiskType::kPlayer2, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kPlayer1, DiskType::kPlayer2, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kPlayer2, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty} 
  };
  Board student;
  InitBoard(student);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)0);
  
  DropDiskToBoard(student, DiskType::kPlayer1, (int)1);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)1);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)1);

  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)3);

  REQUIRE(AreEqual(solution, student.board));
  REQUIRE(SearchForWinner(student, DiskType::kPlayer2, WinningDirection::kLeftDiag) == true);
  REQUIRE(CheckForWinner(student, DiskType::kPlayer2) == true);
  REQUIRE(CheckForWinner(student, DiskType::kPlayer1) == false);
  REQUIRE(SearchForWinner(student, DiskType::kPlayer2, WinningDirection::kRightDiag) == false);
}
TEST_CASE("Left Diagonal Edge Player1", "Full Column") {
  DiskType solution[kBoardHeight][kBoardWidth] = { 
    {DiskType::kPlayer1, DiskType::kPlayer2, DiskType::kPlayer2, DiskType::kPlayer1, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kPlayer1, DiskType::kPlayer2, DiskType::kPlayer1, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kPlayer2, DiskType::kPlayer1, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kPlayer1, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty} 
  };
  Board student;
  InitBoard(student);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)0);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)0);
  
  DropDiskToBoard(student, DiskType::kPlayer2, (int)1);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)1);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)1);

  DropDiskToBoard(student, DiskType::kPlayer2, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)3);

  REQUIRE(AreEqual(solution, student.board));
  REQUIRE(SearchForWinner(student, DiskType::kPlayer1, WinningDirection::kLeftDiag) == true);
  REQUIRE(CheckForWinner(student, DiskType::kPlayer1) == true);
  REQUIRE(CheckForWinner(student, DiskType::kPlayer2) == false);
  REQUIRE(SearchForWinner(student, DiskType::kPlayer2, WinningDirection::kVertical) == false);
}
TEST_CASE("Right Diagonal Edge", "Full Column") {
  DiskType solution[kBoardHeight][kBoardWidth] = { 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer2, DiskType::kPlayer1, DiskType::kPlayer2, DiskType::kPlayer1}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer2, DiskType::kPlayer2, DiskType::kPlayer1}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer2, DiskType::kPlayer2}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer2}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty} 
  };
  Board student;
  InitBoard(student);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)4);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)6);
  
  DropDiskToBoard(student, DiskType::kPlayer2, (int)4);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)6);

  DropDiskToBoard(student, DiskType::kPlayer2, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)6);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)6);

  REQUIRE(AreEqual(solution, student.board));
  REQUIRE(SearchForWinner(student, DiskType::kPlayer2, WinningDirection::kRightDiag) == true);
  REQUIRE(CheckForWinner(student, DiskType::kPlayer2) == true);
  REQUIRE(SearchForWinner(student, DiskType::kPlayer2, WinningDirection::kHorizontal) == false);
}
TEST_CASE("Right Diagonal Edge Player2", "Full Column") {
  DiskType solution[kBoardHeight][kBoardWidth] = { 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer1, DiskType::kPlayer2, DiskType::kPlayer1, DiskType::kPlayer2}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer1, DiskType::kPlayer1, DiskType::kPlayer2}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer1, DiskType::kPlayer1}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kPlayer1}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty} 
  };
  Board student;
  InitBoard(student);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)3);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)4);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)6);
  
  DropDiskToBoard(student, DiskType::kPlayer1, (int)4);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer2, (int)6);

  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)6);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)6);

  REQUIRE(AreEqual(solution, student.board));
  REQUIRE(SearchForWinner(student, DiskType::kPlayer1, WinningDirection::kRightDiag) == true);
  REQUIRE(CheckForWinner(student, DiskType::kPlayer1) == true);
  REQUIRE(SearchForWinner(student, DiskType::kPlayer2, WinningDirection::kLeftDiag) == false);
}
TEST_CASE("Multiple Verticles", "Full Column") {
  Board student;
  InitBoard(student);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)5);

  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);
  DropDiskToBoard(student, DiskType::kPlayer1, (int)2);


  REQUIRE(CheckForWinner(student, DiskType::kPlayer1));
}





/////////////////////////////////////////////////////////////////////////////////////////////