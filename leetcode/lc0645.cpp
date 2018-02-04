//
// Created by aleafall on 17-9-15.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		int sum = 0;
		vector<int> ans{0, 0};
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[abs(nums[i])-1] > 0) {
				nums[abs(nums[i])-1] *= -1;
			} else {
				ans.front() = abs(nums[i]);
			}
			sum += abs(nums[i]);
		}
		ans.back() = (int) nums.size() * (nums.size() + 1) / 2 - sum + ans.front();
		return ans;
	}
};
