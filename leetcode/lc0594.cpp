//
// Created by aleafall on 17-5-21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findLHS(vector<int> &nums) {
		int ans = 0;
		sort(nums.begin(), nums.end());
		int i = 0, j = 1;
		while (j < nums.size()) {
			if (nums[j] - nums[i] == 1) {
				while (j < nums.size() && nums[j] - nums[i] == 1) {
					++j;
				}
				ans = max(ans, j - i);
			} else if (nums[j] - nums[i] < 1) {
				++j;
			} else {
				++i;
			}
		}
		return ans;
	}
};
