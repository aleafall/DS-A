//
// Created by aleafall on 17-9-11.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int ans = 1;
		vector<int> dp(nums.size(), 1);
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] > nums[i - 1]) {
				dp[i] = dp[i - 1] + 1;
				ans = max(ans, dp[i]);
			}
		}
		return ans;
	}
};
