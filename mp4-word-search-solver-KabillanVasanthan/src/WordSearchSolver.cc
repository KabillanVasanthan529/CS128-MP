#include "WordSearchSolver.hpp"


bool WordSearchSolver::LocationInBounds(size_t row, size_t col) const {
  return ((row < puzzle_height_) && (col < puzzle_width_));
}
WordSearchSolver::WordSearchSolver(const std::vector<std::vector<char>>& puzzle) {
  for(unsigned int i = 0; i < puzzle.size(); i++) {
    puzzle_.push_back(puzzle.at(i)); 
  }
  puzzle_height_ = puzzle_.size();
  puzzle_width_ = puzzle_[0].size();
}

WordLocation WordSearchSolver::CheckHorizontal(const std::string& word) {
  
  for(unsigned int i = 0; i < puzzle_height_; i++) {
    unsigned int count = 0;
    std::vector<CharPositions> characters;
    for (unsigned int j = 0; j < puzzle_width_; j++) {
      if(word.at(count) == puzzle_.at(i).at(j)) {
        characters.push_back(CharPositions{word.at(count), i, j});
        count++;
      } else {
        if (puzzle_.at(i).at(j) == word.at(0)) {
          characters.clear();
          characters.push_back(CharPositions{word.at(0), i, j});
          count = 1; 
        } else {
          count = 0;
          characters.clear();
        }
      }
      if(count >= word.size()) {
        return WordLocation{word, characters}; 
      }
    }
  }
  return WordLocation{};
}
WordLocation WordSearchSolver::CheckVertical(const std::string& word) {
  for(unsigned int i = 0; i < puzzle_width_; i++) {
    unsigned int count = 0;
    std::vector<CharPositions> characters;
    for (unsigned int j = 0; j < puzzle_height_; j++) {
      if(word.at(count) == puzzle_.at(j).at(i)) {
        characters.push_back(CharPositions{word.at(count), j, i});
        count++;
      } else {
        if (puzzle_.at(j).at(i) == word.at(0)) {
          characters.clear();
          characters.push_back(CharPositions{word.at(0), j, i});
          count = 1; 
        } else {
          count = 0;
          characters.clear();
        }
      }
      if(count >= word.size()) {
        return WordLocation{word, characters};
      }
    }
  }
  return WordLocation{};
}
WordLocation WordSearchSolver::CheckLeftDiagonal(const std::string& word) {
  unsigned int cross = 0;
  if(puzzle_height_ > puzzle_width_) {
    cross = puzzle_height_;
  } else {
    cross = puzzle_width_;
  }
  
  for (unsigned int i = 0; i < puzzle_height_; i++) {
    for (unsigned int j = 0; j < puzzle_width_; j++) {
      unsigned int count = 0;
      std::vector<CharPositions> characters;
      for (unsigned int k = 0; k < cross; k++) {
        if(i+k >= puzzle_height_ || static_cast<int>(j)-static_cast<int>(k) < 0) {
          break;
        }
        if(word.at(count) == puzzle_.at(i+k).at(j-k)) {
          characters.push_back(CharPositions{word.at(count), i+k, j-k});
          count++;
        } else {
          count = 0;
          characters.clear();
        }
        if (count >= word.size()) {
          return WordLocation{word, characters};
        }
      } 
    }
  }
  return WordLocation{};
}
WordLocation WordSearchSolver::CheckRightDiagonal(const std::string& word) {
  unsigned int cross = 0;
  if(puzzle_height_ > puzzle_width_) {
    cross = puzzle_height_;
  } else {
    cross = puzzle_width_;
  }
  for (unsigned int i = 0; i < puzzle_height_; i++) {
    for (unsigned int j = 0; j < puzzle_width_; j++) {
      unsigned int count = 0;
      std::vector<CharPositions> characters;
      for (unsigned int k = 0; k < cross; k++) {
        if(i+k >= puzzle_height_ || j+k >= puzzle_width_) {
          break;
        }
        if(word.at(count) == puzzle_.at(i+k).at(j+k)) {
          characters.push_back(CharPositions{word.at(count), i+k, j+k});
          count++;
        } else {
          count = 0;
        }
        if(count >= word.size()) {
          return WordLocation{word, characters};
        }
      } 
    }
  }
  return WordLocation{};
}

WordLocation WordSearchSolver::FindWord(const std::string& word, CheckDirection direction) {
  if(!CheckHorizontal(word).word.empty() && direction == CheckDirection::kHorizontal) {
    return CheckHorizontal(word);
  }
  if(!CheckVertical(word).word.empty() && direction == CheckDirection::kVertical) {
    return CheckVertical(word);
  }
  if(!CheckLeftDiagonal(word).word.empty() && direction == CheckDirection::kLeftDiag) {
    return CheckLeftDiagonal(word);
  }
  if(!CheckRightDiagonal(word).word.empty() && direction == CheckDirection::kRightDiag) {
    return CheckRightDiagonal(word);
  }
  return WordLocation{};
}
WordLocation WordSearchSolver::FindWord(const std::string& word) {
  if(!FindWord(word, CheckDirection::kHorizontal).word.empty()) {
    return FindWord(word, CheckDirection::kHorizontal);
  }
  if(!FindWord(word, CheckDirection::kVertical).word.empty()) {
    return FindWord(word, CheckDirection::kVertical);
  }
  if(!FindWord(word, CheckDirection::kLeftDiag).word.empty()) {
    return FindWord(word, CheckDirection::kLeftDiag);
  }
  if(!FindWord(word, CheckDirection::kRightDiag).word.empty()) {
    return FindWord(word, CheckDirection::kRightDiag);
  }
  return WordLocation{};
}
