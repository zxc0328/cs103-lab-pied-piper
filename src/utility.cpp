#include <string>
#include <iostream>
#include <iomanip>
#include "HuffmanNode.h"

using namespace std;

void parsingArgs(int argCount, char** argArr, string& inputFileName, string& outputFileName){
	for (int i=0;i<argCount;i++) {
		if (strcmp(argArr[i], "-encode") == 0) {
			inputFileName = string(argArr[i+1]);
		}
		if (strcmp(argArr[i], "-o") == 0) {
			outputFileName = string(argArr[i+1]);
		}
	}
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