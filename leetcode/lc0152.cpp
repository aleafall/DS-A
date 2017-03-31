//
// Created by aleafall on 17-3-19.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		vector<int> f(nums.size()), g(nums.size());
		f[0] = g[0] = nums[0];
		int ans = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			f[i] = max(max(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
			g[i] = min(min(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
			ans = max(ans, f[i]);
		}
		return ans;
	}
};
