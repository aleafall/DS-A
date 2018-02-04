//
// Created by aleafall on 17-9-16.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isPossible(vector<int>& nums) {
		vector<vector<int>> vi;
		for (int i = 0; i < nums.size(); ++i) {
			bool put = 0;
			for (int j = 0; j < vi.size(); ++j) {
				if (nums[i] == vi[j].back() + 1) {
					vi[j].push_back(nums[i]);
					put = 1;
					break;
				}
			}
			if (!put) {
				vi.emplace_back(vector<int>{nums[i]});
			}
		}
		for (auto &&item :vi) {
			if (item.size() < 3) {
				return 0;
			}
		}
		return 1;
	}
};
