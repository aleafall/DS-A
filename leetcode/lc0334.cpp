//
// Created by aleafall on 17-3-10.
//

#include <iostream>
#include <algorithm>


using namespace std;

class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		vector<int> vi;
		for (int i = 0; i < nums.size(); ++i) {
			auto it = lower_bound(vi.begin(), vi.end(), nums[i]);
			if (it != vi.end()) {
				*it = nums[i];
			} else {
				vi.push_back(nums[i]);
				if (vi.size() > 2) {
					return 1;
				}
			}
		}
		return 0;
	}
};


