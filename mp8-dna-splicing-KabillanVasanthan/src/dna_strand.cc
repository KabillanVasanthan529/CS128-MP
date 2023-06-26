#include "dna_strand.hpp"

#include <stdexcept>
#include <cassert>

DNAstrand::~DNAstrand() {
    while(head_ != nullptr) {
        Node* next = head_->next;
        delete head_;
        head_ = next;
    }
}
unsigned int CharLen(const char* pattern) {
    unsigned int len = 0;
    for(unsigned int i = 0; pattern[i] != '\0'; ++i) {
        len++;
    }
    return len;
}
void DNAstrand::PushBack(Node* node) {
    if(head_ == nullptr) {
        head_ = node;
        tail_ = node;
    } else {
        Node* temp = node;
        tail_->next = temp;
        tail_ = temp;
    }
}
/*
void DNAstrand::Print() {
    Node* temp = head_;
    while (temp -> next != nullptr) {
        std::cout << temp -> data << std::endl;
        temp = temp -> next;
    }
    std::cout << tail_ -> data << std::endl;
}
*/

Node* DNAstrand::StrandDelete(int last, Node* head_, int len) {
    if (last == -1) 
        throw std::exception();
    Node* cur = head_;
    int i = 0;
    while (i < last + len) {
        if (i >= last) {
            Node* next = cur -> next;
            delete cur;
            cur = next; 
        } else 
            cur = cur -> next;
        i++;
    }
    return cur;
}

void DNAstrand::SpliceIn(const char* pattern, DNAstrand& to_splice_in) {
    Node* current = head_;
    int len = (int)(CharLen(pattern)); int match = 0; int count = 0; int last = -1;
    while (current != nullptr) {
        if (current -> data == pattern[match])
            match++;
        else {
            if (pattern[0] == current -> data) 
                match = 1;
            else
                match = 0;
        }   
        count++;
        if (match == len)
            last = (int)(count - len);
        current = current -> next;
    }
    Node* cur = StrandDelete(last, head_, len);
    Node* temp = head_;
    int j = 0;
    if (last == 0) {
        head_ = to_splice_in.head_;
    } else {
        while (j < count) {
            if (j == last - 1) 
                temp -> next = to_splice_in.head_; 
            if (temp -> next != nullptr) 
                temp = temp -> next;
            j++;
        }
    }
    to_splice_in.head_ = nullptr;
    to_splice_in.tail_ = nullptr;
    Node* it = head_;
    while (it -> next != nullptr) 
        it = it -> next;
    if (cur == nullptr) 
        tail_ = to_splice_in.tail_;
    else 
        it -> next = cur;
}
