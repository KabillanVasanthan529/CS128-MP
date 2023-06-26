#include <iostream>

#include "dna_strand.hpp"
#include "node.hpp"

int main() {
    DNAstrand strand;
    Node* node1 = new Node('c');
    Node* node2 = new Node('t');
    Node* node3 = new Node('g');
    Node* node4 = new Node('a');
    Node* node5 = new Node('a');
    Node* node6 = new Node('t');
    Node* node7 = new Node('t');
    Node* node8 = new Node('c');
    Node* node9 = new Node('g');
    std::cout << "here" << std::endl;

    strand.PushBack(node1);
    strand.PushBack(node2);
    strand.PushBack(node3);
    strand.PushBack(node4);
    strand.PushBack(node5);
    strand.PushBack(node6);
    strand.PushBack(node7);
    strand.PushBack(node8);
    strand.PushBack(node9);
    //strand.Print();

    DNAstrand to_splice_in;
    Node* nodes1 = new Node('t');
    Node* nodes2 = new Node('g');
    Node* nodes3 = new Node('a');
    Node* nodes4 = new Node('t');
    Node* nodes5 = new Node('c');
    to_splice_in.PushBack(nodes1);
    to_splice_in.PushBack(nodes2);
    to_splice_in.PushBack(nodes3);
    to_splice_in.PushBack(nodes4);
    to_splice_in.PushBack(nodes5);

    char pattern[] = "ctgaattcg";

    std::cout << "here" << std::endl;
    strand.SpliceIn(pattern, to_splice_in);
    //strand.Print();
}