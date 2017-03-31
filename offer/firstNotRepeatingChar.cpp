//
// Created by aleafall on 17-2-17.
//

#include <iostream>

using namespace std;

class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		int hashTable[256] = {0};
		for (auto item:str) {
			hashTable[item]++;
		}
		for (int i = 0; i < str.size(); ++i) {
			if (hashTable[str[i]] == 1) {
				return i;
			}
		}
		return -1;
	}
};
