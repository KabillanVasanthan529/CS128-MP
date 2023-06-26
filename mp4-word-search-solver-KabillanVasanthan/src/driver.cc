#include <iostream>
#include <string>
#include <vector>

#include "WordSearchSolver.hpp"
#include "CharPositions.hpp"

int main() {
  std::vector<std::vector<char>> puzzle{{'h', 'e', 'h', 'o', 'h'},
                                        {'e', 'e', 'e', 'o', 'e'},
                                        {'l', 'h', 'h', 'o', 'h'},
                                        {'l', 'f', 'e', 'l', 'e'},
                                        {'h', 'e', 'h', 'e', 'y'}};
  WordSearchSolver wss(puzzle);
  std::cout << wss.FindWord("hey", CheckDirection::kVertical);
  //std::cout << wss.FindWord("hello");
}