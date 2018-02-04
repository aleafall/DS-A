//
// Created by aleafall on 17-5-30.
//

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum & 1) {
			return 0;
		}
		int size = sum / 2;
		vector<int> dp(size + 1, 0);
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = size; j >= nums[i]; --j) {
				dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
			}
		}
		return dp[size] == size;
	}
};
