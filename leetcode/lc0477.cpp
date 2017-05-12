//
// Created by aleafall on 17-4-29.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int totalHammingDistance(vector<int>& nums) {
		int ans = 0;
		for (int i = 0; i < 32; ++i) {
			int cnt = 0;
			for (auto &&item :nums) {
				cnt += (item >> i) & 1;
			}
			ans += cnt * ((int) nums.size() - cnt);
		}
		return ans;
	}
};

