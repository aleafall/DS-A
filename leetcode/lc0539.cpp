//
// Created by aleafall on 17-9-27.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findMinDifference(vector<string>& timePoints) {
		int ans = 0x3fffffff;
		const int mod = 24 * 60;
		int n = timePoints.size();
		sort(timePoints.begin(), timePoints.end());
		for (int i = 0; i < n; ++i) {
			auto &bigger = timePoints[(i + n) % n];
			auto &smaller = timePoints[(i - 1 + n) % n];
			int diff=(stoi(bigger.substr(0, 2)) * 60 + stoi(bigger.substr(3, 2))) -
			         (stoi(smaller.substr(0, 2))) * 60 - stoi(smaller.substr(3, 2));
			if (diff < 0) {
				diff += mod;
			}
			ans = max(ans, diff);
		}
		return ans;
	}
};
