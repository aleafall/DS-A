//
// Created by aleafall on 17-9-8.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int findLongestChain(vector<vector<int>>& pairs) {
		unordered_map<string,int> mp;
		sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b) {
			if (a.front() != b.front()) {
				return a.front() < b.front();
			}
			return a.back() < b.back();
		});
		int ans = 1;
		vector<int> dp(pairs.size() + 1, 1);
		for (int i = 1; i < pairs.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (pairs[i].front() > pairs[j].back()) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			ans = max(ans, dp[i]);
		}
		return ans;
	}
};
