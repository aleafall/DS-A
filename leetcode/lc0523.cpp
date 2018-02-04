//
// Created by aleafall on 17-5-31.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		vector<int> dp(nums.size() + 1, 0);
		for (int i = 1; i <= nums.size(); ++i) {
				dp[i] = dp[i - 1] + nums[i - 1];
		}
		for (int i = 0; i < nums.size() - 1; ++i) {
			for (int j = i + 2; j <= nums.size(); ++j) {
				if (k) {
					if ((dp[j] - dp[i]) % k == 0) {
						return 1;
					}
				} else if (dp[j] - dp[i] == 0) {
					return 1;
				}
			}
		}
		return 0;
	}
};

int main() {
	Solution solution;
	vector<int> vi{23, 2, 4, 6, 7};
	int k = -6;
	auto ans = solution.checkSubarraySum(vi, k);
	cout << ans << endl;
    return 0;
}
