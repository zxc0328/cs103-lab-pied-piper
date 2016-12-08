#include <iostream>
#include <map>
#include "encoding.h"
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main() {

  freqTable freqTable;
  encodingMap encodingMap;
  HuffmanNode* HuffmanTree;
  string encondeStr = "";
  float  originalSize = 0;

  ifstream infile; 
  infile.open("tomsawyer.txt"); 

	freqTable = buildFrequencyTable(infile);
	HuffmanTree = buildEncodingTree(freqTable);

	for(freqTableItr iterator = freqTable.begin(); iterator != freqTable.end(); iterator++) {
  		//cout << (char)iterator->first << " " << iterator->second << endl;
	}

	//cout << HuffmanTree->one->one << endl;
	encodingMap = buildEncodingMap(HuffmanTree);
  //freqPairsVector = sortFrequencyTable(freqTable);
	
	cout << "copmpress ···"<< endl;
	ifstream infile2; 
	infile2.open("tomsawyer.txt"); 
	while (true) {
		originalSize += 1;
      int ch = infile2.get();
      if (infile2.fail()) {
           break;
      }
      encondeStr += encodingMap[ch];
  }  

  ofstream outfile("tomsawyer.pp",ios::binary | ios::app);
 cout << "write encoding map header ···"<< endl;
  // write encoding map header
  for(encodingMapItr iterator = encodingMap.begin(); iterator != encodingMap.end(); iterator++) {
  		outfile << iterator->first << ":" << iterator->second << endl;
	}
  //cout << sizeof(encondeStrCharArr) << endl;
	// vector<char> v(encondeStr.begin(), encondeStr.end());
	// char* encondeStrCharArr = &v[0];
	cout << "write encoded bits ···"<< endl;
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
  cout << "all done, copmpression rate: " <<  (float)size/originalSize <<endl;
	return 0;
}




