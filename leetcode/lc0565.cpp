//
// Created by aleafall on 17-5-28.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int arrayNesting(vector<int>& nums) {
		int ans = 0;
		bool vis[nums.size()] = {0};
		int cnt = 0, index = 0;
		while (cnt < nums.size()) {
			int now = index, temp = 0;
			while (vis[now] == 0) {
				++cnt, ++temp;
				vis[now] = 1;
				now = nums[now];
			}
			ans=max(ans,temp);
			++index;
		}
		return ans;
	}
};
