//
// Created by aleafall on 16-10-5.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int> &nums) {
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		int len = nums.size();
		for (int i = 0; i < len - 2; ++i) {
			if (nums[i] + nums[i + 1] + nums[i + 2] > 0) {
				break;
			}
			if (nums[i] + nums[len - 2] + nums[len - 1] < 0) {
				continue;
			}
			int target = -nums[i], front = i + 1, back = len - 1;
			while (front < back) {
				int sum = nums[front] + nums[back];
				if (sum < target) {
					++front;
				} else if (sum > target) {
					--back;
				} else {
					vector<int> now{nums[i], nums[front], nums[back]};
					ans.push_back(now);
					while (front < back && nums[front] == now[1]) {
						++front;
					}
					while (front < back && nums[back] == now[2]) {
						--back;
					}
				}
			}
			while (i + 1 < len && nums[i + 1] == nums[i]) {
				++i;
			}
		}
		return ans;
	}
};
