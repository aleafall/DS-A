//
// Created by aleafall on 17-11-15.
//

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		int pre = 0, sum = accumulate(nums.begin(), nums.end(), 0);
		for (int i = 0; i < nums.size(); ++i) {
			if (sum - pre - nums[i] == pre) {
				return i;
			}
			pre += nums[i];
		}
		return -1;
	}
};
