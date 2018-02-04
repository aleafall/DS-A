//
// Created by aleafall on 17-9-2.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
	bool dfs(vector<int> &sidesLength, const vector<int> &matches, int index, int target) {
		if (index == matches.size())
			return sidesLength[0] == sidesLength[1] && sidesLength[1] == sidesLength[2] &&
			       sidesLength[2] == sidesLength[3];
		for (int i = 0; i < 4; ++i) {
			if (sidesLength[i] + matches[index] > target) {
				continue;
			}
			int j = i;
			for (j--; j >= 0; --j) {
				if (sidesLength[j] == sidesLength[i]) {
					break;
				}
			}
			if (j != -1) {
				continue;
			}
			sidesLength[i] += matches[index];
			if (dfs(sidesLength, matches, index + 1, target))
				return true;
			sidesLength[i] -= matches[index];
		}
		return false;
	}

public:
	bool makesquare(vector<int> &nums) {
		if (nums.empty()) return false;
		vector<int> sidesLength(4, 0);
		int sum = 0;
		for (auto &&item :nums) {
			sum += item;
		}
		if (sum % 4) {
			return 0;
		}
		return dfs(sidesLength, nums, 0, sum / 4);
	}
};