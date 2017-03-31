//
// Created by aleafall on 17-2-5.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (nums.size() <= 1) {
			return 0;
		}
		map<int,vector<int>> mp;
		for (int i = 0; i < nums.size(); ++i) {
			mp[nums[i]].push_back(i);
		}
		for (auto item:mp) {
			if (item.second.size() > 1) {
				for (int i = 0; i < item.second.size() - 1; ++i) {
					if (item.second[i + 1] - item.second[i] <= k) {
						return 1;
					}
				}
			}
		}
		return 0;
	}
};
