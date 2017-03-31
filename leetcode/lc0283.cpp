//
// Created by aleafall on 17-2-5.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		if (nums.empty()) {
			return;
		}
		int cnt=0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i]) {
				nums[cnt++] = nums[i];
			}
		}
		for (int i = cnt; i < nums.size(); ++i) {
			nums[i] = 0;
		}
	}
};
