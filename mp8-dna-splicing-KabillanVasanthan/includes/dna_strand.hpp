#ifndef DNA_STRAND_HPP
#define DNA_STRAND_HPP

#include "node.hpp"

class DNAstrand {
public:
  DNAstrand() = default;
  DNAstrand(const DNAstrand& rhs) = delete;
  DNAstrand& operator=(const DNAstrand& rhs) = delete;
  ~DNAstrand();
  void PushBack(Node* node);
  void Print();
  void SpliceIn(const char* pattern, DNAstrand& to_splice_in);
  Node* StrandDelete(int last, Node* head_, int len);
  
private:
  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};

#endif