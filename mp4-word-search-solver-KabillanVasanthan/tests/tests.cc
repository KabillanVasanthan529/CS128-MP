// clang-format off
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//  Written By : Student Name                    Environment : ubuntu:bionic               //
//  Date ......: 2021/02/10                      Compiler ...: clang-10                    //
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

#include "CharPositions.hpp"
#include "WordLocation.hpp"
#include "WordSearchSolver.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                             Helpers/Constants //
/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
//                                Test Cases //
/////////////////////////////////////////////////////////////////////////////////////////////
bool WordLocEqual(WordLocation a, WordLocation b) {
    if (a.word != b.word) {
        return false;
    }
    if (a.char_positions.size() != b.char_positions.size()) {
        return false;
    }
    for (unsigned int i = 0; i < a.char_positions.size(); i++) {
        if(a.char_positions.at(i).character != b.char_positions.at(i).character) {
            return false;
        }
        if(a.char_positions.at(i).row != b.char_positions.at(i).row) {
            return false;
        }
        if(a.char_positions.at(i).col != b.char_positions.at(i).col) {
            return false;
        }
    }
    return true;
}


TEST_CASE("True == True", "") { REQUIRE(true == true); }
TEST_CASE("All Sizes", "All Sizes") {
    std::vector<std::vector<char>> puzzle1{{'h', 'e', 'l', 'l', 'o'},
                                        {'e', 'e', 'e', 'o', 'e'},
                                        {'l', 'h', 'h', 'o', 'h'},
                                        {'l', 'f', 'e', 'l', 'e'},
                                        {'h', 'e', 'h', 'e', 'y'}};
    WordSearchSolver wss(puzzle1);
    std::vector<CharPositions> pos;
    pos.push_back(CharPositions{'h',0,0});
    pos.push_back(CharPositions{'e',0,1});
    pos.push_back(CharPositions{'l',0,2});
    pos.push_back(CharPositions{'l',0,3});
    pos.push_back(CharPositions{'o',0,4});

    WordLocation sol = WordLocation{"hello", pos};
    WordLocation ans = wss.FindWord("hello");
    REQUIRE(WordLocEqual(sol, ans));

    std::vector<std::vector<char>> puzzle2{{'h', 'e', 'l', 'l', 'o'},
                                        {'e', 'e', 'e', 'o', 'e'},
                                        {'l', 'h', 'h', 'o', 'h'},
                                        {'l', 'f', 'e', 'l', 'e'},
                                        {'h', 'e', 'h', 'e', 'y'}};
    WordSearchSolver wss2(puzzle2);
    std::vector<CharPositions> pos2;
    pos2.push_back(CharPositions{'h',0,0});
    pos2.push_back(CharPositions{'e',0,1});
    pos2.push_back(CharPositions{'l',0,2});
    

    WordLocation sol2 = WordLocation{"hel", pos2};
    WordLocation ans2 = wss2.FindWord("hel");
    REQUIRE(WordLocEqual(sol2, ans2));
}
TEST_CASE("Horizontal", "Horizontal") {
    std::vector<std::vector<char>> puzzle1{{'h', 'e', 'l', 'l', 'o'},
                                        {'e', 'e', 'e', 'o', 'e'},
                                        {'l', 'h', 'h', 'o', 'h'},
                                        {'l', 'f', 'e', 'l', 'e'},
                                        {'h', 'e', 'h', 'e', 'y'}};
    WordSearchSolver wss(puzzle1);
    std::vector<CharPositions> pos;
    pos.push_back(CharPositions{'h',0,0});
    pos.push_back(CharPositions{'e',0,1});
    pos.push_back(CharPositions{'l',0,2});
    pos.push_back(CharPositions{'l',0,3});
    pos.push_back(CharPositions{'o',0,4});

    WordLocation sol = WordLocation{"hello", pos};
    WordLocation ans = wss.FindWord("hello", CheckDirection::kHorizontal);
    WordLocation gen = wss.FindWord("hello");
    WordLocation wrong1 = wss.FindWord("hello", CheckDirection::kVertical);
    WordLocation wrong2 = wss.FindWord("hello", CheckDirection::kLeftDiag);
    WordLocation wrong3 = wss.FindWord("hello", CheckDirection::kRightDiag);
    REQUIRE(WordLocEqual(sol, ans));
    REQUIRE(WordLocEqual(sol, gen));
    REQUIRE_FALSE(WordLocEqual(sol, wrong1));
    REQUIRE_FALSE(WordLocEqual(sol, wrong2));
    REQUIRE_FALSE(WordLocEqual(sol, wrong3));
}
TEST_CASE("Vertical", "Vertical") {
    std::vector<std::vector<char>> puzzle1{{'h', 't', 'b', 'l', 'o'},
                                        {'e', 'e', 'e', 'o', 'e'},
                                        {'l', 'h', 'h', 'o', 'h'},
                                        {'l', 'f', 'e', 'l', 'e'},
                                        {'o', 'e', 'h', 'e', 'y'}};
    WordSearchSolver wss(puzzle1);
    std::vector<CharPositions> pos;
    pos.push_back(CharPositions{'h',0,0});
    pos.push_back(CharPositions{'e',1,0});
    pos.push_back(CharPositions{'l',2,0});
    pos.push_back(CharPositions{'l',3,0});
    pos.push_back(CharPositions{'o',4,0});

    WordLocation sol = WordLocation{"hello", pos};
    WordLocation ans = wss.FindWord("hello", CheckDirection::kVertical);
    WordLocation gen = wss.FindWord("hello");
    WordLocation wrong1 = wss.FindWord("hello", CheckDirection::kHorizontal);
    WordLocation wrong2 = wss.FindWord("hello", CheckDirection::kLeftDiag);
    WordLocation wrong3 = wss.FindWord("hello", CheckDirection::kRightDiag);
    REQUIRE(WordLocEqual(sol, ans));
    REQUIRE(WordLocEqual(sol, gen));
    REQUIRE_FALSE(WordLocEqual(sol, wrong1));
    REQUIRE_FALSE(WordLocEqual(sol, wrong2));
    REQUIRE_FALSE(WordLocEqual(sol, wrong3));
}
TEST_CASE("Right Diag", "Right Diag") {
    std::vector<std::vector<char>> puzzle1{{'h', 't', 'b', 'l', 'o'},
                                        {'e', 'e', 'e', 'o', 'e'},
                                        {'l', 'h', 'l', 'o', 'h'},
                                        {'t', 'f', 'e', 'l', 'e'},
                                        {'o', 'e', 'h', 'e', 'o'}};
    WordSearchSolver wss(puzzle1);
    std::vector<CharPositions> pos;
    pos.push_back(CharPositions{'h',0,0});
    pos.push_back(CharPositions{'e',1,1});
    pos.push_back(CharPositions{'l',2,2});
    pos.push_back(CharPositions{'l',3,3});
    pos.push_back(CharPositions{'o',4,4});

    WordLocation sol = WordLocation{"hello", pos};
    WordLocation ans = wss.FindWord("hello", CheckDirection::kRightDiag);
    WordLocation gen = wss.FindWord("hello");
    WordLocation wrong1 = wss.FindWord("hello", CheckDirection::kHorizontal);
    WordLocation wrong2 = wss.FindWord("hello", CheckDirection::kLeftDiag);
    WordLocation wrong3 = wss.FindWord("hello", CheckDirection::kVertical);
    REQUIRE(WordLocEqual(sol, ans));
    REQUIRE(WordLocEqual(sol, gen));
    REQUIRE_FALSE(WordLocEqual(sol, wrong1));
    REQUIRE_FALSE(WordLocEqual(sol, wrong2));
    REQUIRE_FALSE(WordLocEqual(sol, wrong3));
}
TEST_CASE("Left Diag", "Left Diag") {
    std::vector<std::vector<char>> puzzle1{{'h', 't', 'b', 'l', 'h'},
                                        {'e', 't', 'e', 'e', 'e'},
                                        {'l', 'h', 'l', 'o', 'h'},
                                        {'t', 'l', 'e', 'l', 'e'},
                                        {'o', 'e', 'h', 'e', 'o'}};
    WordSearchSolver wss(puzzle1);
    std::vector<CharPositions> pos;
    pos.push_back(CharPositions{'h',0,4});
    pos.push_back(CharPositions{'e',1,3});
    pos.push_back(CharPositions{'l',2,2});
    pos.push_back(CharPositions{'l',3,1});
    pos.push_back(CharPositions{'o',4,0});

    WordLocation sol = WordLocation{"hello", pos};
    WordLocation ans = wss.FindWord("hello", CheckDirection::kLeftDiag);
    WordLocation gen = wss.FindWord("hello");
    WordLocation wrong1 = wss.FindWord("hello", CheckDirection::kHorizontal);
    WordLocation wrong2 = wss.FindWord("hello", CheckDirection::kRightDiag);
    WordLocation wrong3 = wss.FindWord("hello", CheckDirection::kVertical);
    REQUIRE(WordLocEqual(sol, ans));
    REQUIRE(WordLocEqual(sol, gen));
    REQUIRE_FALSE(WordLocEqual(sol, wrong1));
    REQUIRE_FALSE(WordLocEqual(sol, wrong2));
    REQUIRE_FALSE(WordLocEqual(sol, wrong3));
}
TEST_CASE("Empty", "Empty") {
    std::vector<std::vector<char>> puzzle1{{'h', 't', 'b', 'l', 'h'},
                                        {'e', 't', 'e', 'e', 'e'},
                                        {'l', 'h', 'l', 'o', 'h'},
                                        {'t', 't', 'e', 'l', 'e'},
                                        {'o', 'e', 'h', 'e', 'o'}};
    WordSearchSolver wss(puzzle1);

    WordLocation sol = WordLocation{};
    WordLocation Horizontal = wss.FindWord("hello", CheckDirection::kLeftDiag);
    WordLocation gen = wss.FindWord("hello");
    WordLocation Left = wss.FindWord("hello", CheckDirection::kHorizontal);
    WordLocation Right = wss.FindWord("hello", CheckDirection::kRightDiag);
    WordLocation Vert = wss.FindWord("hello", CheckDirection::kVertical);
    REQUIRE(WordLocEqual(sol, Horizontal));
    REQUIRE(WordLocEqual(sol, gen));
    REQUIRE(WordLocEqual(sol, Left));
    REQUIRE(WordLocEqual(sol, Right));
    REQUIRE(WordLocEqual(sol, Vert));
}
TEST_CASE("RepeatHor", "Repeat") {
    std::vector<std::vector<char>> puzzle1{{'h', 'e', 'h', 'e', 'y'},
                                        {'e', 't', 'e', 'e', 'e'},
                                        {'l', 'h', 'l', 'o', 'h'},
                                        {'t', 't', 'e', 'l', 'e'},
                                        {'o', 'e', 'h', 'e', 'o'}};
    WordSearchSolver wss(puzzle1);
    std::vector<CharPositions> pos;
    pos.push_back(CharPositions{'h',0,2});
    pos.push_back(CharPositions{'e',0,3});
    pos.push_back(CharPositions{'y',0,4});

    WordLocation sol = WordLocation{"hey", pos};
    WordLocation Horizontal = wss.FindWord("hey", CheckDirection::kHorizontal);
    WordLocation gen = wss.FindWord("hey");
    REQUIRE(WordLocEqual(sol, Horizontal));
    REQUIRE(WordLocEqual(sol, gen));
}
TEST_CASE("RepeatVer", "Repeat") {
    std::vector<std::vector<char>> puzzle1{{'h', 't', 'h', 't', 'y'},
                                        {'e', 't', 'e', 'e', 'e'},
                                        {'h', 'h', 'l', 'o', 'h'},
                                        {'e', 't', 'e', 'l', 'e'},
                                        {'y', 'e', 'h', 'e', 'o'}};
    WordSearchSolver wss(puzzle1);
    std::vector<CharPositions> pos;
    pos.push_back(CharPositions{'h',2,0});
    pos.push_back(CharPositions{'e',3,0});
    pos.push_back(CharPositions{'y',4,0});

    WordLocation sol = WordLocation{"hey", pos};
    WordLocation vert = wss.FindWord("hey", CheckDirection::kVertical);
    WordLocation gen = wss.FindWord("hey");
    REQUIRE(WordLocEqual(sol, vert));
    REQUIRE(WordLocEqual(sol, gen));
}
TEST_CASE("RepeatRight", "Repeat") {
    std::vector<std::vector<char>> puzzle1{{'h', 't', 'h', 't', 'y'},
                                        {'e', 'e', 'e', 'e', 'e'},
                                        {'h', 'h', 'h', 'o', 'h'},
                                        {'t', 't', 'e', 'e', 't'},
                                        {'y', 'e', 'h', 't', 'y'}};
    WordSearchSolver wss(puzzle1);
    std::vector<CharPositions> pos;
    pos.push_back(CharPositions{'h',2,2});
    pos.push_back(CharPositions{'e',3,3});
    pos.push_back(CharPositions{'y',4,4});

    WordLocation sol = WordLocation{"hey", pos};
    WordLocation right = wss.FindWord("hey", CheckDirection::kRightDiag);
    WordLocation gen = wss.FindWord("hey");
    REQUIRE(WordLocEqual(sol, right));
    REQUIRE(WordLocEqual(sol, gen));
}
TEST_CASE("RepeatLeft", "Repeat") {
    std::vector<std::vector<char>> puzzle1{{'h', 't', 'h', 't', 'h'},
                                        {'e', 'e', 'e', 'e', 'e'},
                                        {'h', 'h', 'h', 'o', 'h'},
                                        {'t', 'e', 'e', 't', 't'},
                                        {'y', 'e', 'h', 't', 'y'}};
    WordSearchSolver wss(puzzle1);
    std::vector<CharPositions> pos;
    pos.push_back(CharPositions{'h',2,2});
    pos.push_back(CharPositions{'e',3,1});
    pos.push_back(CharPositions{'y',4,0});

    WordLocation sol = WordLocation{"hey", pos};
    WordLocation left = wss.FindWord("hey", CheckDirection::kLeftDiag);
    WordLocation gen = wss.FindWord("hey");
    REQUIRE(WordLocEqual(sol, left));
    REQUIRE(WordLocEqual(sol, gen));
}
TEST_CASE("Partially off", "Repeat") {
    std::vector<std::vector<char>> puzzle1{{'h', 't', 'h', 't', 'h'},
                                        {'e', 'e', 'e', 'e', 'e'},
                                        {'h', 'h', 'h', 'o', 'h'},
                                        {'t', 'e', 'e', 't', 't'},
                                        {'y', 'e', 'h', 'e', 'l'}};
    WordSearchSolver wss(puzzle1);

    WordLocation sol = WordLocation{};
    WordLocation gen = wss.FindWord("hello");
    REQUIRE(WordLocEqual(sol, gen));
}
TEST_CASE("Non-square puzzle", "Repeat") {
    std::vector<std::vector<char>> puzzle1{{'h', 't', 'h', 't', 'h'},
                                        {'e', 'e', 'e', 'e', 'e'},
                                        {'h', 'h', 'h', 'o', 'h'},
                                        {'t', 'e', 'e', 't', 't'},
                                        {'y', 'e', 'h', 'e', 'l'},
                                        {'h', 'e', 'l', 'l', 'o'}};
    WordSearchSolver wss(puzzle1);
    std::vector<CharPositions> pos;
    pos.push_back(CharPositions{'h',5,0});
    pos.push_back(CharPositions{'e',5,1});
    pos.push_back(CharPositions{'l',5,2});
    pos.push_back(CharPositions{'l',5,3});
    pos.push_back(CharPositions{'o',5,4});

    WordLocation sol = WordLocation{"hello", pos};
    WordLocation gen = wss.FindWord("hello");
    REQUIRE(WordLocEqual(sol, gen));
}


/////////////////////////////////////////////////////////////////////////////////////////////