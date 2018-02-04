//
// Created by aleafall on 17-9-11.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findNumberOfLIS(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		bool update = 0;
		int Max = 1, len = 0, ans = 0;
		vector<int> dp(nums.size(), 1);
		vector<int> a(nums.size(), 1);
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[i] > nums[j]) {
					update = 1;
					if (dp[j] + 1 > dp[i]) {
						dp[i] = dp[j] + 1;
						a[i] = a[j];
					}
					else if (dp[j] + 1 == dp[i]) {
						a[i] += a[j];
					}
				}
			}
			if (dp[i] > Max) {
				Max = dp[i];
				ans = a[i];
			}
			else if (dp[i] == Max) {
				ans += a[i];
			}
		}
		return update ? ans : (int) nums.size();
	}
};

int main() {
    Solution solution;
	vector<int> vi{1, 3, 2};
	cout << solution.findNumberOfLIS(vi) << endl;
    return 0;
};