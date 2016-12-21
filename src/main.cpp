#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include "utility.h"
#include "encoding.h"

using namespace std;

int main(int argc, char*argv[]) {
	string compressFileName = "";
	string decompressFileName = "";
	string outputFileName = "";
	freqTable freqTable;
  encodingMap encodingMap;
  HuffmanNode* HuffmanTree;
  ifstream infile;

  // paring args
	parsingArgs(argc, argv, inputFileName, outputFileName);

	// if no filename is set, return
	if (compressFileName.length() == 0 && decompressFileName.length == 0) {
		cout << "Please enter the name of the file to be processed" << endl;
		return 0;
	}

	if (compressFileName.length() > 0) {
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
	}else if (decompressFileName.length() > 0) {
		// decompress(infileForCompress, outfile, encodingMap);
	}
	

	return 0;
}




