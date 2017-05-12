//
// Created by aleafall on 17-3-14.
//

#include<iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int rob(vector<int> &nums) {
		int ans = 0;
		/*if (nums.empty()) {
			return 0;
		}
		vector<int> dp(nums.size(), 0);
		for (int i = 0; i < nums.size(); ++i) {
			dp[i] = nums[i];
		}
		for (int i = 0; i < nums.size() - 1; ++i) {
			if (i > 2) {
				dp[i] = max(dp[i], max(dp[i - 2] + nums[i], dp[i - 3] + nums[i]));
			} else if (i > 1) {
				dp[i] = max(dp[i], nums[i] + dp[i - 2]);
			}
			ans = max(ans, dp[i]);
		}
		dp[1] = nums[1];
		for (int i = 1; i < nums.size(); ++i) {
			if (i > 2) {
				dp[i] = max(dp[i], max(dp[i - 2] + nums[i], dp[i - 3] + nums[i]));
			} else if (i > 1) {
				dp[i] = max(dp[i], nums[i] + dp[i - 2]);
			}
			ans = max(ans, dp[i]);
		}
		return ans;*/
		if (nums.empty()) {
			return 0;
		}
		if (nums.size() == 1) {
			return nums.front();
		}
//		return max(rob(nums, 0, nums.size() - 2), rob(nums, 1, nums.size() - 1));
		int x = rob(nums, 0, nums.size() - 2);
		cout << "in" << endl;
		int y = rob(nums, 1, nums.size() - 1);
		return max(x, y);
	}

	int rob(vector<int> &nums, int l, int r) {
		int pre = 0, cur = 0;
		for (int i = l; i <= r; i++) {
			int temp = max(pre + nums[i], cur);
			pre = cur;
			cur = temp;
			cout << "pre cur " << pre << " " << cur << endl;
		}
		return cur;
	}
};


int main() {
	vector<int> vi{1, 2, 3, 4, 5};
	Solution solution;
	cout << solution.rob(vi) << endl;
}
