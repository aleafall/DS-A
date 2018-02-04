//
// Created by aleafall on 17-9-13.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool PredictTheWinner(vector<int> &nums) {
		if (!nums.size() & 1) {
			return 1;
		}
		/*vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
		for (int i = 0; i < nums.size(); ++i) {
			dp[i][i] = nums[i];
		}
		return getSum(0, nums.size() - 1,nums, dp) >= 0;*/
		vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
		for (int i = 0; i < nums.size(); ++i) {
			dp[i][i] = nums[i];
		}
		for (int len = 1; len < nums.size(); ++len) {
			for (int i = 0; i + len < nums.size(); ++i) {
				int end = i + len;
				dp[i][end] = max(nums[i] - dp[i + 1][end], nums[end] - dp[i][end - 1]);
			}
		}
		return dp[0][nums.size() - 1] >= 0;
	}

	int getSum(int begin, int end,vector<int> &nums, vector<vector<int>> &dp) {

		dp[begin][end] = begin == end ? nums[begin] : max(dp[begin][begin] + getSum(begin + 1, end,nums, dp),
		                                                       dp[end][end] + getSum(begin, end - 1,nums, dp));
		return dp[begin][end];
	}
};
