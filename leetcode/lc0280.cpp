//
// Created by aleafall on 17-9-12.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void wiggleSort(vector<int> &nums) {
		if (nums.empty() || nums.size < 2) {
			return;
		}
		for (int i = 1; i < nums.size(); ++i) {
			if ((i % 2 && nums[i] < nums[i - 1]) || (!i % 2 && nums[i] > nums[i - 1])) {
				swap(nums[i], nums[i - 1]);
			}
		}
	}
};

