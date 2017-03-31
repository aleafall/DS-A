//
// Created by aleafall on 17-3-10.
//

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int ans = INT32_MAX, ret = 0;
		sort(nums.begin(), nums.end());
		int len = (int) nums.size();
		for (int i = 0; i < len - 2; ++i) {
			int front = i + 1, back = len - 1;
			while (front < back) {
				int sum = nums[i] + nums[front] + nums[back];
				if (abs(sum - target) < ans) {
					ans = abs(sum - target);
					ret = sum;
					if (ret == 0) {

						cout << "find\n";
					}
				}
				if (sum > target) {
					--back;
				} else if (sum < target) {
					++front;
				} else {
					return sum;
				}
				/*int t1 = nums[front], t2 = nums[back];
				while (front < back && nums[front] == t1) {
					++front;
				}
				while (front < back && nums[back] == t2) {
					--back;
				}*/
			}
			while (i + 1 < len && nums[i + 1] == nums[i]) {
				++i;
			}
		}
		return ret;
	}
};


