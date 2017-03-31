//
// Created by aleafall on 16-12-11.
//
#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool wordBreak(string s, vector<string> &wordDict) {
		if (s.empty() || wordDict.empty()) {
			return 0;
		}
		int target = 0, len = wordDict.size();
		int index = 0;
		while (index < s.size()) {
			int temp = index;
			for (int i = 0; i < len && index < s.size(); ++i) {
				if (index + wordDict[i].size() <= s.size() && wordDict[i] == s.substr(index, wordDict[i].size())) {
					index += wordDict[i].size();
					--len;
					swap(wordDict[i], wordDict[len]);
				}
			}
			if (temp == index) {
				return 0;
			}
		}
		return 1;
	}
};

