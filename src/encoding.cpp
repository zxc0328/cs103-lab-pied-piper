// #include <map>
// #include "encoding.h"

freqPairs sortFrequencyTable(map<int, int>& freqTable){
	freqPairs pairs;
	for (freqTableItr itr = freqTable.begin(); itr != freqTable.end(); ++itr){
		pairs.push_back(*itr);
	}

	sort(pairs.begin(), pairs.end(), [=](pair<int, int>& a, pair<int, int>& b){
    return a.second < b.second;
	})
	return pairs;
}
