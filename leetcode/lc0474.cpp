//
// Created by aleafall on 17-3-15.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		sort(strs.begin(), strs.end(), [](const string &a, const string &b) {
			if (a.size() != b.size()) {
				return a.size() < b.size();
			}
			return a < b;
		});
		for (int i = 0; i < strs.size(); ++i) {
			for (int j = 0; j < strs[i].size(); ++j) {
				strs[i][j] == '0' ? --m : --n;
				if (m <= 0 && n <= 0) {
					return i + 1;
				}
			}
		}
		return 0;
	}
};
