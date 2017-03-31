//
// Created by aleafall on 17-3-1.
//

#include <iostream>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (s.empty() || numRows <= 1) {
			return s;
		}
		string ans;
		int index = 0, col = 0;
		for (int i = 0; i < numRows; ++i) {
			for (int j = 0, index = i; index < s.size(); ++j, index = (2 * numRows - 2) * j + i) {
				ans += s[index];
				if (i == 0 || i == numRows - 1) {
					continue;
				}
				if (index + (numRows - i - 1) * 2 < s.size()) {
					ans += s[index + (numRows - 1 - i) * 2];
				}
			}
		}
		return ans;
	}
};
