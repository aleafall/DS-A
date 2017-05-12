//
// Created by aleafall on 17-4-21.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		int ans = 0, sum = 0;
		unordered_map<int, int> mp;
		mp[0] = -1;
		for (int i = 0; i < nums.size(); ++i) {
			sum += nums[i] ? -1 : 1;
			if (mp.count(sum)) {
				ans = max(ans, i - mp[sum]);
			} else {
				mp[sum] = i;
			}
		}
		return ans;
	}
};
