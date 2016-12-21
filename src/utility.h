#ifndef _utility_h
#define _utility_h

#include <string>
#include <iostream>
#include "HuffmanNode.h"

using namespace std;

void wirteBit(string encodeStr, ofstream& outfile);
void readBit(string& encodeStr, ifstream& input);
void printTree(HuffmanNode* p, int indent);
void parsingArgs(int argCount, char** argArr, string& compressFileName, string& decompressFileName, string& outputFileName);
#endif