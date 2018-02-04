//
// Created by aleafall on 17-10-9.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int ans = 1;
		vector<pair<int, int>> dp(nums.size(), pair<int, int>(1, 1));
		for (int i = 1; i < nums.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[i] > nums[j]) {
					dp[i].second = max(dp[i].second, dp[j].first + 1);
				} else if (nums[i] < nums[j]) {
					dp[i].first = max(dp[i].first, dp[j].second + 1);
				}
			}
			ans = max(ans, max(dp[i].first, dp[i].second));
		}
		return ans;
	}
};
