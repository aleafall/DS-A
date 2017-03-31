//
// Created by aleafall on 17-2-23.
//

#include <iostream>

using namespace std;

class Solution {
public:
	static int hashTable[256] = {0};
	string str;
	//Insert one char from stringstream
	void Insert(char ch) {
		hashTable[ch]++;
		str += ch;
	}

	//return the first appearence once char in current stringstream
	char FirstAppearingOnce() {
		for (auto &&item : str) {
			if (hashTable[item] == 1) {
				return (char) item;
			}
		}
		return '#';
	}
};

