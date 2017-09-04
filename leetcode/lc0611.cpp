//
// Created by t-xiuyan on 6/17/2017.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int triangleNumber(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int ans = 0;
		sort(nums.begin(), nums.end());
		for (int i = nums.size() - 1; i >= 2; --i) {
			int left = 0, right = i - 1;
			while (left < right) {
				if (nums[left] + nums[right] > nums[i]) {
					ans += right - left;
					--right;
				} else {
					++left;
				}
			}
		}
		return ans;
	}
};
