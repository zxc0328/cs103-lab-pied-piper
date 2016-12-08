#ifndef _encoding_h
#define _encoding_h

#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef map<int, int> freqTable;
typedef map<int, int>::iterator freqTableItr;
typedef vector< pair<int, int> > freqPairs;
typedef vector< pair<int, int> >::iterator freqPairsItr;

freqPairs sortFrequencyTable(map<int, int>& freqTable);
freqTable buildFrequencyTable(istream& input);
#endif