//
// Created by aleafall on 17-4-29.
//

//find the difference, then partittion
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		vector<int> ans{0, 0};
		int diff = 0;
		for (auto &&item :nums) {
			diff ^= item;
		}
		diff &= -diff;
		for (auto &&item :nums) {
			if (diff & item) {
				ans.front() ^= item;
			} else {
				ans.back() ^= item;
			}
		}
		return ans;
	}
};
