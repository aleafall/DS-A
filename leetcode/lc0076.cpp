//
// Created by aleafall on 17-3-9.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		int ans = s.size() + 1, i = 0, j = 0;
		string res;
		while (j < s.size()) {
			while (!isContain(s, t, i, j) && j < s.size()) {
				j++;
			}
			while (isContain(s, t, i, j)) {
				if (ans > j - i) {
					ans = j - i;
					res = s.substr(i, j);

				}
				++i;
			}
		}
		return ans == s.size() + 1 ? "" : res;
	}

	bool isContain(const string &s, const string &t, int left, int right) {
		int hashTable[256] = {0};
		for (int i = 0; i < t.size(); ++i) {
			hashTable[t[i]]--;
		}
		for (int i = left; i < right; ++i) {
			hashTable[s[i]]++;
		}
		for (int i = 0; i < 256; ++i) {
			if (hashTable[i] < 0) {
				return 0;
			}
		}
		return 1;
	}
};