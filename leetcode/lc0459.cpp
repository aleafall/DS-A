//
// Created by aleafall on 17-10-7.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		if (s.empty()) {
			return 0;
		}
		for (int i = 1; i <= s.size() / 2; ++i) {
			if (leftShiftStr(s, i) == s) {
				return 1;
			}
		}
		return 0;
	}
	string leftShiftStr(string &str,int d){
		string ans = str.substr(d);
		ans += str.substr(0, d);
		return ans;
	}
};
