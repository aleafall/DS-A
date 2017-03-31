//
// Created by aleafall on 17-3-1.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> vi;
	Solution(vector<int> nums):vi(nums) {
	}

	int pick(int target) {
		int cnt = 0, ans = -1;
		for (int i = 0; i < vi.size(); ++i) {
			if (vi[i] == target) {
				++cnt;
				if (rand() % cnt == 0) {
					ans = i;
				}
			}
		}
		return ans;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
