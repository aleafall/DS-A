//
// Created by aleafall on 17-5-28.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxCount(int m, int n, vector<vector<int>> &ops) {
		pair<int, int> range = make_pair(m, n);
		for (int i = 0; i < ops.size(); ++i) {
			range.first = min(range.first, ops[i][0]);
			range.second = min(range.second, ops[i][1]);
		}
		return range.first * range.second;
	}
};
