//
// Created by aleafall on 17-3-11.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	string findLongestWord(string s, vector<string>& d) {
		if (s.empty() || d.empty()) {
			return "";
		}
		sort(d.begin(), d.end(), [](const string &a, const string &b) {
			if (a.size() != b.size()) {
				return a.size() > b.size();
			}
			return a < b;
		});
		for (int i = 0; i < d.size(); ++i) {
			int tag = 0;
			for (int j = 0; j < s.size(); ++j) {
				if (s[j] == d[i][tag]) {
					++tag;
				}
				if (tag == d[i].size()) {
					return d[i];
				}
			}
		}
		return "";
	}
};
