//
// Created by aleafall on 17-3-10.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:

	vector<vector<int>> fourSum(vector<int> &nums, int target) {
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		int len = (int) nums.size();
		for (int i = 0; i < len - 3; ++i) {
			if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
				break;
			}
			if (nums[i] + nums[len - 3] + nums[len - 2] + nums[len - 1] < target) {
				continue;
			}
			for (int j = i + 1; j < len - 2; ++j) {
				if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
					break;
				}
				if (nums[i] + nums[j] + nums[len - 2] + nums[len - 1] < target) {
					continue;
				}
				int front = j + 1, back = len - 1;
				while (front < back) {
					int sum = nums[i] + nums[j] + nums[front] + nums[back];
					if (sum < target) {
						++front;
					} else if (sum > target) {
						--back;
					} else {
						vector<int> now{nums[i], nums[j], nums[front], nums[back]};
						ans.push_back(now);
						while (front < back && nums[front] == now[2]) {
							++front;
						}
						while (front < back && nums[back] == now[3]) {
							--back;
						}
					}
				}
				while (j + 1 < len && nums[j + 1] == nums[j]) {
					++j;
				}
			}
			while (i + 1 < len && nums[i + 1] == nums[i]) {
				++i;
			}
		}
		return ans;
	}
};
