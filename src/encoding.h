#ifndef _encoding_h
#define _encoding_h

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include "HuffmanNode.h"

using namespace std;

typedef map<int, int> freqTable;
typedef map<int, int>::iterator freqTableItr;
typedef vector< pair<int, int> > freqPairs;
typedef vector< pair<int, int> >::iterator freqPairsItr;
typedef map<int, string> encodingMap;
typedef map<int, string>::iterator encodingMapItr;

freqPairs sortFrequencyTable(map<int, int>& freqTable);
freqTable buildFrequencyTable(ifstream& input);
HuffmanNode* buildEncodingTree(freqTable& freqTable);
encodingMap buildEncodingMap(HuffmanNode* HuffmanTree);
void traversalTree(HuffmanNode* node, encodingMap& map,string code);
void compress(ifstream& input, ofstream& output, encodingMap& encodingMap);
#endif