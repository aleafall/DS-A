//
// Created by aleafall on 17-4-27.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool find132pattern(vector<int>& nums) {
		if (nums.size() < 3) {
			return 0;
		}
		for (int i = 0; i < nums.size() - 2; ++i) {
			if (nums[i] < nums[i + 2] && nums[i + 2] < nums[i + 1]) {
				return 1;
			}
		}
		return 0;
	}
};
