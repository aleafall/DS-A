//
// Created by aleafall on 17-2-5.
//

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int left = 0, right = (int) (nums.size() - 1);
		while (left < right) {
			int mid = (left + right) / 2;
			if (nums[mid] < nums[mid + 1]) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}
		return left;
	}
};
