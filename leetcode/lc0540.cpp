//
// Created by aleafall on 17-9-27.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (mid > left && nums[mid] == nums[mid - 1]) {
				if ((mid - 1 - left ) & 1) {
					right = mid - 2;
				} else {
					left = mid + 1;
				}
			} else if (mid < right && nums[mid] == nums[mid + 1]) {
				if ((mid - left) & 1) {
					right = mid - 1;
				} else {
					left = mid + 2;
				}
			} else if (mid > left && mid < right && nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
				return nums[mid];
			}
		}
		return nums[left];
	}
};
