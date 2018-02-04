//
// Created by aleafall on 17-5-15.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		if (nums.empty() || nums[0].empty() || r * c != (int) nums.size() * (int) nums[0].size()) {
			return nums;
		}
		vector<vector<int>> ans(r, vector<int>(c, 0));
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = 0; j < nums[i].size(); ++j) {
				ans[(i * 2 + j) / c][(i * 2 + j) % c] = nums[i][j];
			}
		}
		return ans;
	}
};
