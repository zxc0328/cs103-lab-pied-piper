#include <iostream>
#include <map>
#include "encoding.h"

using namespace std;

int main() {
  freqTable freqTable;
  freqPairs freqPairsVector;

	freqTable = buildFrequencyTable(cin);
	freqPairsVector = sortFrequencyTable(freqTable);
  
	for(freqPairsItr iterator = freqPairsVector.begin(); iterator != freqPairsVector.end(); iterator++) {
 		cout << iterator->first << " " << iterator->second << endl;
	}
	return 0;
}

// should be placed in encoding.cpp, but passing cin as argment fires an error under OS X 10.11
map<int, int> buildFrequencyTable(istream& input) {
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