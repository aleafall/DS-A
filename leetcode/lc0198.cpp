//
// Created by aleafall on 17-3-14.
//

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int ans = 0;
		vector<int> dp(nums.size(), 0);
		for (int i = 0; i < nums.size(); ++i) {
			dp[i] = nums[i];
			/*for (int j = 0; j < i; ++j) {
				if (i != j + 1) {
					dp[i] = max(dp[i], dp[j] + nums[i]);

				}
			}*/
			if (i > 2) {
				dp[i] = max(dp[i], max(dp[i - 2] + nums[i], dp[i - 3] + nums[i]));
			} else if (i > 1) {
				dp[i] = max(dp[i], nums[i] + dp[i - 2]);
			}
			ans = max(ans, dp[i]);
		}
		return ans;
	}
};
