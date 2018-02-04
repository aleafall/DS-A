//
// Created by t-xiuyan on 6/24/2017.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findPairs(vector<int> &nums, int k) {
		sort(nums.begin(), nums.end());
		unordered_map<int,int> mp;
		int ans = 0;
		for (auto &&item :nums) {
			mp[item]++;
		}
		for (auto &&item :mp) {
			if (k) {
				ans += (int) (item.second > 1);
			} else {
				ans += (int) (mp.count(item.first + k));
			}
		}
		return ans;
	}
};
