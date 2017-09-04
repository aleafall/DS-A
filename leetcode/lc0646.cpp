//
// Created by t-xiuyan on 7/23/2017.
//

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
	int findLongestChain(vector<vector<int>>& pairs) {
		sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b) {
			if (a.front() != b.back()) {
				return a.front() > b.back();
			}
			return a.back() < b.front();
		});
		int ans = 0;
		vector<int> dp(pairs.size() + 1, 1);
		for (int i = 0; i < pairs.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (pairs[j].front() > pairs[i].back()) {
					dp[i + 1] = max(dp[i + 1], dp[j + 1] + 1);
				}
			}
			ans = max(ans, dp[i + 1]);
		}
		return ans;
	}
};

