#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include "utility.h"
#include "encoding.h"

using namespace std;

int main(int argc, char*argv[]) {
	string inputFileName = "";
	string outputFileName = "";
	freqTable freqTable;
  encodingMap encodingMap;
  HuffmanNode* HuffmanTree;
  ifstream infile;

  // paring args
	parsingArgs(argc, argv, inputFileName, outputFileName);

	//reading file
	if (inputFileName.length() == 0) {
		cout << "Please enter the name of the file to be encoded" << endl;
		return 0;
	}
	infile.open(inputFileName); 
	cout << "Reading file: " << inputFileName << "..." << endl;
	
	// building frequency table
	freqTable = buildFrequencyTable(infile);
	// building encoding tree
	HuffmanTree = buildEncodingTree(freqTable);
	// building encoding map
	encodingMap = buildEncodingMap(HuffmanTree);
	
	ifstream infileForCompress; 
	infileForCompress.open(inputFileName); 
	ofstream outfile(outputFileName,ios::binary | ios::app);

	// compress
	compress(infileForCompress, outfile, encodingMap);

	return 0;
}




