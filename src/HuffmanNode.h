#ifndef _huffmannode_h
#define _huffmannode_h

const int NOT_A_CHAR = -1;

struct HuffmanNode {
    int character;       // character being represented by this node
    int count;           // number of occurrences of that character
    HuffmanNode* zero;   // 0 (left) subtree (NULL if empty)
    HuffmanNode* one;    // 1 (right) subtree (NULL if empty)

    /*
     * Constructs a new node to store the given character and its count,
     * along with the given child pointers.
     */
    HuffmanNode(int character = NOT_A_CHAR, int count = 0,
                HuffmanNode* zero = 0, HuffmanNode* one = 0);

    bool isLeaf() const;
};

#endif