//
// Created by aleafall on 17-2-6.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int ans = 0;
		int dp[nums.size()];
		fill(dp, dp + nums.size(), 1);
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[i] > nums[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			ans = max(ans, dp[i]);
		}
		vector<int> res;
		return ans;
	}
};
