#include <map>
#include <queue>
#include <functional>
#include <fstream>
#include "encoding.h"
#include <fstream>

void compress(ifstream& input, ofstream& outfile, encodingMap& encodingMap){
	float  originalSize = 0;
	string encondeStr = "";
	
	cout << "Copmpress ···"<< endl;

	while (true) {
		originalSize += 1;
      int ch = input.get();
      if (input.fail()) {
           break;
      }
      encondeStr += encodingMap[ch];
  }  

 	cout << "Writing encoding map header ···"<< endl;

  for(encodingMapItr iterator = encodingMap.begin(); iterator != encodingMap.end(); iterator++) {
  		outfile << iterator->first << ":" << iterator->second << endl;
	}

	cout << "Wriing encoded bits ···"<< endl;

	const int size = encondeStr.size()/8+1;
	const char* encondeStrCharArr = strdup(encondeStr.c_str());
  char* buffer = new char[size];
	for (int i=0;i<size;i++) {
		int j = 0;
		int ch = 0;
		while (j<7) {
			if ((i*8+j) < encondeStr.size()) {
			  if (encondeStrCharArr[i*8+j] == '1') {
			  	ch += 1*(2^(7-j));
			  }
			}
			j += 1;
		}
		buffer[i] = ch;
	}
  outfile.write((char*) buffer,size);
  cout << "All done, copmpression rate: " <<  (float)size/originalSize <<endl;
}

// void decompress(){

// }

map<int, int> buildFrequencyTable(ifstream& input) {
	  cout << "Building frequence table ···"<< endl;
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
		cout << "Building enconding tree ···"<< endl;
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
		cout << "Building enconding map ···"<< endl;
		encodingMap encodingMap;
    traversalTree(HuffmanTree->zero, encodingMap, "0");
    traversalTree(HuffmanTree->one, encodingMap, "1");
    return encodingMap;             
}