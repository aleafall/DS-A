//
// Created by aleafall on 17-5-20.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findUnsortedSubarray(vector<int> &nums) {
		int ans = 0, left = 0, right = (int) nums.size() - 1;
		while (left < right && nums[left] <= nums[left + 1]) {
			++left;
		}
		while (right > 0 && nums[right] >= nums[right - 1]) {
			--right;
		}
		if (right > left) {
			int Min = *min_element(nums.begin() + left, nums.begin() + right + 1);
			int Max = *max_element(nums.begin() + left, nums.begin() + right + 1);
			while (left >= 0 && nums[left] > Min) {
				--left;
			}
			while (right < nums.size() && nums[right] < Max) {
				++right;
			}
			ans = right - left - 1;
		}
		return ans;
	}
};
