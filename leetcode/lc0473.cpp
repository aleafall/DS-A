//
// Created by t-xiuyan on 9/3/2017.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool makesquare(vector<int>& nums) {
		int sum=0,Max=0;
		for (auto &&item :nums) {
			sum += item;
			Max = max(Max, item);
		}
		int edge = sum / 4;
		if (sum % 4 || Max > edge) {
			return 0;
		}
		for (int k = 0; k < 3; ++k) {
			vector<vector<int>> dp(nums.size()+ 1, vector<int>(edge+1,0));
			for (int i = 1; i <= nums.size(); ++i) {
				for (int j = nums[i - 1]; j <= edge; ++j) {
					dp[i][j] = max(dp[i - 1][j - nums[i - 1]] + nums[i - 1], dp[i - 1][j]);
				}
			}
			if (dp[nums.size()][edge] != edge) {
				return 0;
			}
			int e = edge;
			for (int i = nums.size(); i > 0; --i) {
				if (dp[i][e] != dp[i - 1][e]) {
					e -= nums[i - 1];
					swap(nums[i - 1], nums.back());
					nums.pop_back();
				}
			}
		}
		return 1;
	}
};
