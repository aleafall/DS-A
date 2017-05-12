//
// Created by aleafall on 17-4-18.
//

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int jump(vector<int> &nums) {
		/*if (nums.empty()) {
			return 0;
		}
		vector<int> dp(nums.size(), INT32_MAX);
		dp[0] = 0;
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = 1; j <= i + nums[i]&&j<nums.size(); ++j) {
				dp[j] = min(dp[j], dp[i] + 1);
			}
		}*/
//		return dp.back();
		int ans = 0, end = 0, next = 0;
		for (int i = 0; i < nums.size() - 1; ++i) {
			next = max(next, i + nums[i]);
			if (i == end) {
				end = next;
				++ans;
			}
		}
		return ans;
	}
};
