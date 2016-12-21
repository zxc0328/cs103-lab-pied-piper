#include <string>
#include <iostream>
#include <iomanip>
#include "HuffmanNode.h"

using namespace std;

void parsingArgs(int argCount, char** argArr, string& compressFileName, string& decompressFileName, string& outputFileName){
	for (int i=0;i<argCount;i++) {
		if (strcmp(argArr[i], "-encode") == 0) {
			compressFileName = string(argArr[i+1]);
		}
        if (strcmp(argArr[i], "-decode") == 0) {
            decompressFileName = string(argArr[i+1]);
        }
		if (strcmp(argArr[i], "-o") == 0) {
			outputFileName = string(argArr[i+1]);
		}
	}
}

void wirteBit(string encodeStr, ofstream& outfile){
    const int size = encodeStr.size()/8+1;
    const char* encodeStrCharArr = strdup(encodeStr.c_str());
    char* buffer = new char[size];
    for (int i=0;i<size;i++) {
        int j = 0;
        int ch = 0;
        while (j<7) {
            if ((i*8+j) < encodeStr.size()) {
              if (encodeStrCharArr[i*8+j] == '1') {
                ch += 1*(2^(7-j));
              }
            }
            j += 1;
        }
        buffer[i] = ch;
    }
    outfile.write((char*) buffer,size);
}

void readBit(string& str, ifstream& input){
    // todo 
}

void printTree(HuffmanNode* p, int indent)
{
				if(p->one) {
            printTree(p->one, indent+4);
        }
        if (indent) {
            cout << setw(indent) << ' ';
        }
        if (p->one) cout<<" /\n" << setw(indent) << ' ';
        cout<< p->count <<  "\n ";
        if(p->zero) {
            cout << setw(indent) << ' ' <<" \\\n";
            printTree(p->zero, indent+4);
        }
}