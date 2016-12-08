#include "HuffmanNode.h"


//static void printHuffmanNode(ostream& out, const HuffmanNode& node, bool showAddress = false);

HuffmanNode::HuffmanNode(int character, int count, HuffmanNode* zero, HuffmanNode* one) {
    this->character = character;
    this->count = count;
    this->zero = zero;
    this->one = one;
}

bool HuffmanNode::isLeaf() const {
    return zero == 0 && one == 0;
}

// bool HuffmanNode::operator()(HuffmanNode& node1, HuffmanNode& node2){
//     return node1.count < node2.count;
// }