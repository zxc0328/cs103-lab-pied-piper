#include <map>
#include <queue>
#include <iomanip>
#include <functional>
#include "encoding.h"
#include <fstream>

// void printTree(HuffmanNode* node, int indent) {
	
// 	if (!(node->zero == 0)) {
// 			printTree(node->zero, indent + 4);
// 	}
// 	if (!(node->one == 0)) {
// 			printTree(node->one, indent + 4);
// 	}
// 	if (indent) {
// 		std::cout << std::setw(indent) << ' ';
// 	}
	
// 	cout<< node->character << "\n ";
// }

void printTree(HuffmanNode* p, int indent)
{

        if(p->one) {
            printTree(p->one, indent+4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->one) std::cout<<" /\n" << std::setw(indent) << ' ';
        std::cout<< p->count <<  "\n ";
        if(p->zero) {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            printTree(p->zero, indent+4);
        }
}



// not used
freqPairs sortFrequencyTable(map<int, int>& freqTable){
	freqPairs pairs;
	for (freqTableItr itr = freqTable.begin(); itr != freqTable.end(); ++itr){
		pairs.push_back(*itr);
	}

	// sorting with lambda
	sort(pairs.begin(), pairs.end(), [] (pair<int, int>& a, pair<int, int>& b) -> bool{
  	return a.second > b.second;
  });
	return pairs;
}

map<int, int> buildFrequencyTable(ifstream& input) {
    map<int, int> freqTable; 
    while (true) {
      int ch = input.get();
      if (input.fail()) {
           break;
      }
      freqTable[ch] += 1;
  	}  
    return freqTable;          
}

HuffmanNode* buildEncodingTree(freqTable& freqTable) {
		auto cmp = [](HuffmanNode& node1, HuffmanNode& node2) { return node1.count > node2.count;};
		priority_queue<HuffmanNode, vector<HuffmanNode>,decltype(cmp)> q(cmp);

    for(freqTableItr iterator = freqTable.begin(); iterator != freqTable.end(); iterator++) {
 	 		HuffmanNode node;
 	 		node.character = iterator->first;
 	 		node.count = iterator->second;
 			
 	 		q.push(node);
		}

		// if count of q > 2
		while(q.size() > 1) {
      HuffmanNode* root = new HuffmanNode();

			HuffmanNode* nodeLeft = new HuffmanNode(q.top().character, q.top().count, q.top().zero, q.top().one);
			q.pop();
			root->zero = nodeLeft;

			HuffmanNode* nodeRight = new HuffmanNode(q.top().character, q.top().count, q.top().zero, q.top().one);
			root->one  = nodeRight;
			q.pop();

			root->count = nodeLeft->count + nodeRight->count;
			q.push(*root);

    }
    HuffmanNode* result = new HuffmanNode(q.top().character, q.top().count, q.top().zero, q.top().one);

    q.pop();
		HuffmanNode* HuffmanTree = result;

    return HuffmanTree;
}

void traversalTree(HuffmanNode* node, encodingMap &map, string code) {
	if (node->character > 0) {
		map[node->character] = code;
	}

	if (!(node->zero == 0)) {
			traversalTree(node->zero, map, code+"0");
	}
	if (!(node->one == 0)) {
			traversalTree(node->one, map, code+"1");
	}
}




encodingMap buildEncodingMap(HuffmanNode* HuffmanTree) {
		encodingMap encodingMap;
		
		// cout << encodingTree->zero->character << endl;
		// cout << encodingTree->one->character << endl;
    traversalTree(HuffmanTree->zero, encodingMap, "0");
    traversalTree(HuffmanTree->one, encodingMap, "1");
    //printTree(HuffmanTree, 0);
    return encodingMap;             
}