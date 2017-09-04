//
// Created by t-xiuyan on 6/30/2017.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return max(nums[0] * nums[1] * nums.back(), nums.back() * nums[nums.size() - 2] * nums[nums.size() - 3]);
	}
};
