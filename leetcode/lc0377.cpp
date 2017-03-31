//
// Created by aleafall on 16-11-5.
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	int combinationSum4(vector<int> &nums, int target) {
		vector<int> dp(target + 1);
		dp[0] = 1;
		for (int i = 1; i <= target; ++i) {
			for (int j = 0; j < nums.size(); ++j) {
				if (i >= nums[j]) {
					dp[i] += dp[i - j];
				}
			}
		}
		return dp.back();
	}
};

int main() {
	Solution *solution = new Solution;
	vector<int> vi{1, 2, 3};
	int target = 4;
	int ans = solution->combinationSum4(vi, target);
	cout << ans << endl;
	delete solution;
	return 0;
}