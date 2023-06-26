#ifndef CIRCULAR_LINKED_LIST_HPP
#define CIRCULAR_LINKED_LIST_HPP

#include <iostream>

#include "node.hpp"

enum class Order { kASC, kDESC };

template <typename T>
class CircularLinkedList {
public:
  CircularLinkedList() = default;
  CircularLinkedList(const CircularLinkedList<T>& source);
  CircularLinkedList<T>& operator=(const CircularLinkedList<T>& source);
  ~CircularLinkedList();

  void InsertInOrder(const T& data);
  void Reverse();

  template <typename U>
  friend std::ostream& operator<<(std::ostream& os,
                                  const CircularLinkedList<U>& cll);

private:
  Node<T>* head_ = nullptr;
  Node<T>* tail_ = nullptr;
  Order node_order_ = Order::kASC;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const CircularLinkedList<T>& cll) {
  Node<T>* iter = cll.head_;
  // empty list condition
  if (iter == nullptr) {
    os << "Empty list";
    return os;
  }
  // non-empty list condition
  do {
    os << iter->data << '\t';
    iter = iter->next;
  } while (iter != cll.head_);

  return os;
}

template <typename T>
CircularLinkedList<T>::CircularLinkedList(const CircularLinkedList<T>& source) {
  if (source.head_ == nullptr) {
    head_ = nullptr;
    tail_ = nullptr;
    node_order_ = Order::kASC;
  }
  head_ = new Node<T>(source.head_ -> data, nullptr);
  auto temp = source.head_;
  auto current = head_;
  temp = temp -> next;
  while (temp -> next != source.head_) {
    current -> next = new Node<T>(temp -> data, nullptr);
    current = current -> next;
    temp = temp -> next;
  }
  tail_= new Node<T>(temp -> data, head_);
  current -> next = tail_;
}
template <typename T>
CircularLinkedList<T>& CircularLinkedList<T>::operator=(const CircularLinkedList<T>& source) {
  if (&source == this) {
    return *this;
  }
  if (source.head_ == nullptr) {
    head_ = nullptr;
    tail_ = nullptr;
    node_order_ = Order::kASC;
  }
  if (head_ != nullptr) {
    Node<T>* temp = head_ -> next;
    while(temp != head_) {
      Node<T>* next = temp -> next;
      delete temp;
      temp = next;
    }
    delete head_;
  }
  head_ = new Node<T>(source.head_ -> data, nullptr);
  auto tmp = source.head_;
  auto current = head_;
  tmp = tmp -> next;
  while (tmp -> next != source.head_) {
    current -> next = new Node<T>(tmp -> data, nullptr);
    current = current -> next;
    tmp = tmp -> next;
  }
  tail_= new Node<T>(tmp -> data, head_);
  current -> next = tail_;
  return *this;
}
template <typename T>
CircularLinkedList<T>::~CircularLinkedList() {
  if (head_ == nullptr) {
    return;
  }
  Node<T>* temp = head_ -> next;
  while(temp != head_) {
    Node<T>* next = temp -> next;
    delete temp;
    temp = next;
  }
  delete head_;
}
template <typename T>
void CircularLinkedList<T>::InsertInOrder(const T& data) {
  auto node = new Node<T>(data);
  if (head_ == nullptr) {
    head_ = node; head_ -> next = head_; tail_ = head_;
    return;
  }
  Node<T>* temp = head_;
  if (node_order_ == Order::kASC) {
    if (temp -> data >= data) {
      Node<T>* aft = head_;
      head_ = node; head_ -> next = aft; tail_ -> next = head_;
      return;
    }
    while (temp -> next != head_) {
      if (temp -> data <= data && temp -> next -> data >= data) {
        Node<T>* aft = temp -> next;
        temp -> next = node; node -> next = aft;
        return;
      }
      temp = temp -> next;
    }
    tail_ = temp -> next = node; tail_ -> next = head_;
  }
  if (node_order_ == Order::kDESC) {
    if (temp -> data <= data) {
      Node<T>* aft = head_;
      head_ = node; head_ -> next = aft; tail_ -> next = head_;
      return;
    }
    while (temp -> next != head_) {
      if (temp -> data >= data && temp -> next -> data <= data) {
        Node<T>* aft = temp -> next;
        temp -> next = node; node -> next = aft;
        return;
      }
      temp = temp -> next;
    }
    tail_ = temp -> next = node;
    tail_ -> next = head_;
  }
}
template <typename T>
void CircularLinkedList<T>::Reverse() {
  if (head_ != nullptr) {
    auto cur = head_ -> next;
    auto prev = head_;
    auto next = cur -> next;
    while (cur != head_) {
      next = cur -> next;
      cur -> next = prev;
      prev = cur;
      cur = next;
    } 
    cur -> next = prev; 
    head_ = next -> next; 
    tail_ = cur; 
  }
  
  if (node_order_ == Order::kASC) {
    node_order_ = Order::kDESC;
  } else {
    node_order_ = Order::kASC;
  }
}


#endif