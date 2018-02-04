//
// Created by aleafall on 17-10-16.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int findShortestSubArray(vector<int>& nums) {
		unordered_map<int,vector<int>> mp;
		for (int i = 0; i < nums.size(); ++i) {
			if (!mp.count(nums[i])) {
				mp[nums[i]] = {1, i, i};
			} else {
				mp[nums[i]].front()++;
				mp[nums[i]][2] = i;
			}
		}
		int Max = 0, ans = 0x3fffffff;
		for (auto &&item :mp) {
			if (item.second.front() > Max) {
				Max = item.second.front();
				ans = item.second[2] - item.second[1] + 1;
			} else if (item.second.front() == Max && item.second[2] - item.second[1] + 1 < ans) {
				ans = item.second[2] - item.second[1] + 1;
			}
		}
		return ans;
	}
};
