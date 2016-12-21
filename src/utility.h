#ifndef _utility_h
#define _utility_h

#include <string>
#include <iostream>
#include "HuffmanNode.h"

using namespace std;

void printTree(HuffmanNode* p, int indent);
void parsingArgs(int argCount, char** argArr, string& inputFileName, string& outputFileName);
#endif